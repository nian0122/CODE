/**
 * 测试数据生成工具
 * 用于生成外部排序算法的测试数据
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000000  // 最大数值
#define DEFAULT_COUNT 100000  // 默认生成数量

/**
 * 生成随机数测试文件
 * @param filename 输出文件名
 * @param count 生成数量
 */
void generate_random_data(const char* filename, int count) {
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        perror("无法创建测试文件");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d\n", rand() % MAX_NUM);
    }

    fclose(fp);
    printf("已生成测试数据文件: %s (%d条记录)\n", filename, count);
}

/**
 * 生成有序测试文件
 * @param filename 输出文件名
 * @param count 生成数量
 */
void generate_sorted_data(const char* filename, int count) {
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        perror("无法创建测试文件");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d\n", i);
    }

    fclose(fp);
    printf("已生成有序测试文件: %s (%d条记录)\n", filename, count);
}

int main(int argc, char* argv[]) {
    const char* filename = "test_data.txt";
    int count = DEFAULT_COUNT;

    if (argc > 1) {
        filename = argv[1];
    }
    if (argc > 2) {
        count = atoi(argv[2]);
    }

    printf("=== 测试数据生成工具 ===\n");
    generate_random_data(filename, count);
    return 0;
}
