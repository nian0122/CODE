/**
 * 外部排序实现
 * 包含置换选择排序、败者树多路归并等功能
 * 算法步骤：
 * 1. 使用置换选择排序生成初始归并段
 * 2. 构建最佳归并树
 * 3. 使用败者树进行多路归并
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define BUFFER_SIZE 1024  // 缓冲区大小
#define MAX_WAYS 16       // 最大归并路数

// 归并段结构
typedef struct {
    FILE* file;          // 归并段文件指针
    int current_value;   // 当前值
    bool exhausted;      // 是否已耗尽
} Run;

// 败者树节点
typedef struct {
    int index;           // 对应的归并段索引
    int value;           // 当前值
} LoserTreeNode;

// 外部排序上下文
typedef struct {
    Run runs[MAX_WAYS];  // 归并段数组
    int run_count;       // 当前归并段数量
    LoserTreeNode loser_tree[MAX_WAYS * 2];  // 败者树
} ExternalSortContext;

void adjust_loser_tree(ExternalSortContext* ctx, int s);

/**
 * 清理多余的归并段文件
 * @param max_runs 允许保留的最大归并段数量
 * @return 返回实际删除的文件数量，-1表示出错
 */
int remove_excess_run_files(int max_runs) {
    int deleted = 0;
    char filename[32];
    
    for (int i = max_runs; ; i++) {
        snprintf(filename, sizeof(filename), "run_%d.txt", i);
        if (remove(filename) == 0) {
            deleted++;
        } else {
            if (errno == ENOENT) {
                // 文件不存在，停止清理
                break;
            } else {
                perror("删除归并段文件失败");
                return -1;
            }
        }
    }
    
    return deleted;
}

/**
 * 初始化外部排序上下文
 */
void init_external_sort(ExternalSortContext* ctx) {
    ctx->run_count = 0;
    // 初始化败者树
    for (int i = 0; i < MAX_WAYS * 2; i++) {
        ctx->loser_tree[i].index = -1;
        ctx->loser_tree[i].value = INT_MAX;
    }
}

/**
 * 堆调整函数
 */
void heapify(int* arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
}

/**
 * 置换选择排序生成初始归并段
 */
void replacement_selection_sort(FILE* input_file, int memory_size) {
    int* buffer = (int*)malloc(memory_size * sizeof(int));
    if (!buffer) {
        perror("内存分配失败");
        exit(EXIT_FAILURE);
    }

    // 读取初始数据到缓冲区
    int count = 0;
    while (count < memory_size && fscanf(input_file, "%d", &buffer[count]) == 1) {
        count++;
    }

    // 构建初始最小堆
    for (int i = count / 2 - 1; i >= 0; i--) {
        heapify(buffer, count, i);
    }

    int run_number = 0;
    char run_filename[32];
    FILE* run_file = NULL;
    
    while (count > 0) {
        snprintf(run_filename, sizeof(run_filename), "run_%d.txt", run_number++);
        run_file = fopen(run_filename, "w");
        if (!run_file) {
            perror("无法创建归并段文件");
            free(buffer);
            exit(EXIT_FAILURE);
        }

        int last_output = INT_MIN;
        int current_size = count;
        
        while (current_size > 0) {
            fprintf(run_file, "%d\n", buffer[0]);
            last_output = buffer[0];
            
            int next_value;
            if (fscanf(input_file, "%d", &next_value) == 1) {
                if (next_value >= last_output) {
                    buffer[0] = next_value;
                } else {
                    buffer[0] = buffer[current_size - 1];
                    buffer[current_size - 1] = next_value;
                    current_size--;
                }
            } else {
                buffer[0] = buffer[current_size - 1];
                current_size--;
            }
            
            heapify(buffer, current_size, 0);
        }
        
        fclose(run_file);
        
        count = 0;
        for (int i = 0; i < memory_size; i++) {
            if (buffer[i] != INT_MAX) {
                buffer[count++] = buffer[i];
            }
        }
        
        for (int i = count / 2 - 1; i >= 0; i--) {
            heapify(buffer, count, i);
        }
    }
    
    free(buffer);
    printf("生成 %d 个初始归并段\n", run_number);
}

/**
 * 构建最佳归并树
 */
void build_optimal_merge_tree(FILE** run_files, int count) {
    int* heap = (int*)malloc(count * sizeof(int));
    if (!heap) {
        perror("内存分配失败");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        fseek(run_files[i], 0, SEEK_END);
        heap[i] = ftell(run_files[i]) / sizeof(int);
        rewind(run_files[i]);
    }

    for (int i = count / 2 - 1; i >= 0; i--) {
        heapify(heap, count, i);
    }

    while (count > 1) {
        int first = heap[0];
        heap[0] = heap[count - 1];
        count--;
        heapify(heap, count, 0);
        
        int second = heap[0];
        printf("合并归并段: 长度 %d 和 %d\n", first, second);
        
        heap[0] = first + second;
        heapify(heap, count, 0);
    }
    
    free(heap);
}



/**
 * 初始化败者树
 */
void init_loser_tree(ExternalSortContext* ctx) {
    for (int i = 0; i < ctx->run_count; i++) {
        ctx->loser_tree[i + ctx->run_count].index = i;
        if (fscanf(ctx->runs[i].file, "%d", &ctx->loser_tree[i + ctx->run_count].value) != 1) {
            ctx->runs[i].exhausted = true;
            ctx->loser_tree[i + ctx->run_count].value = INT_MAX;
        }
    }

    for (int i = ctx->run_count - 1; i > 0; i--) {
        adjust_loser_tree(ctx, i);
    }
}
/**
 * 调整败者树
 */
void adjust_loser_tree(ExternalSortContext* ctx, int s) {
    int t = (s + ctx->run_count) / 2;
    while (t > 0) {
        if (ctx->loser_tree[s].value > ctx->loser_tree[t].value) {
            LoserTreeNode temp = ctx->loser_tree[s];
            ctx->loser_tree[s] = ctx->loser_tree[t];
            ctx->loser_tree[t] = temp;
        }
        s = t;
        t = t / 2;
    }
    ctx->loser_tree[0] = ctx->loser_tree[s];
}
/**
 * 使用败者树进行多路归并
 */
void multiway_merge(ExternalSortContext* ctx, FILE* output_file) {
    init_loser_tree(ctx);

    while (ctx->loser_tree[0].value != INT_MAX) {
        int min_run = ctx->loser_tree[0].index;
        fprintf(output_file, "%d\n", ctx->loser_tree[0].value);

        if (fscanf(ctx->runs[min_run].file, "%d", &ctx->loser_tree[min_run + ctx->run_count].value) != 1) {
            ctx->runs[min_run].exhausted = true;
            ctx->loser_tree[min_run + ctx->run_count].value = INT_MAX;
        }

        adjust_loser_tree(ctx, min_run + ctx->run_count);
    }
}

/**
 * 测试函数
 */
void test_external_sort() {
    printf("=== 外部排序测试 ===\n");
    
    printf("-- 生成测试数据 --\n");
    system("E:/CODE/datastruct/sort/output/generate_test_data.exe test_data.txt 10000");
    const char* input_filename = "test_data.txt";
    FILE* input_file = fopen(input_filename, "r");
    if (!input_file) {
        perror("无法打开测试输入文件");
        printf("请确保存在测试数据文件: %s\n", input_filename);
        return;
    }
    
    printf("\n-- 生成初始归并段 (最多%d个) --\n", MAX_WAYS);
    replacement_selection_sort(input_file, BUFFER_SIZE);
    fclose(input_file);

    // 确保不会生成过多归并段文件
    if (remove_excess_run_files(MAX_WAYS)) {
        printf("警告: 清理了多余的归并段文件\n");
    }
    
    // 安全打开归并段文件
    FILE* run_files[MAX_WAYS] = {NULL};
    int run_count = 0;
    char run_filename[32];
    
    for (run_count = 0; run_count < MAX_WAYS; run_count++) {
        snprintf(run_filename, sizeof(run_filename), "run_%d.txt", run_count);
        FILE* fp = fopen(run_filename, "r");
        if (!fp) {
            break;
        }
        run_files[run_count] = fp;
    }
    
    if (run_count == 0) {
        printf("错误：未生成任何归并段\n");
        // 清理可能残留的文件
        remove_excess_run_files(0);
        return;
    }
    
    printf("成功打开 %d 个归并段文件\n", run_count);
    
    printf("\n-- 构建最佳归并树 --\n");
    build_optimal_merge_tree(run_files, run_count);
    
    printf("\n-- 多路归并 --\n");
    ExternalSortContext ctx;
    init_external_sort(&ctx);
    ctx.run_count = run_count;
    
    for (int i = 0; i < run_count; i++) {
        rewind(run_files[i]);
        ctx.runs[i].file = run_files[i];
        ctx.runs[i].exhausted = false;
    }
    
    FILE* output_file = fopen("sorted_output.txt", "w");
    if (!output_file) {
        perror("无法创建输出文件");
        for (int i = 0; i < run_count; i++) {
            fclose(run_files[i]);
        }
        return;
    }
    
    multiway_merge(&ctx, output_file);
    fclose(output_file);
    
    printf("\n-- 清理临时文件 --\n");
    for (int i = 0; i < run_count; i++) {
        fclose(run_files[i]);
        snprintf(run_filename, sizeof(run_filename), "run_%d.txt", i);
        remove(run_filename);
    }
    remove("test_input.txt");
    
    printf("\n外部排序测试完成，结果保存在 sorted_output.txt\n");
}

int main() {
    test_external_sort();
    return 0;
}
