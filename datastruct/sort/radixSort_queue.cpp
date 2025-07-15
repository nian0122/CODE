/**
 * 基数排序的队列+链表实现
 * 与radixSort.cpp功能相同但使用不同数据结构
 * 实现方式：
 * 1. 使用10个队列对应0-9的数字
 * 2. 通过链表连接队列节点
 * 3. 分分配和收集两个阶段完成排序
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 队列节点结构
typedef struct QueueNode {
    int value;              // 存储的值
    struct QueueNode* next; // 下一个节点指针
} QueueNode;

// 队列结构
typedef struct {
    QueueNode* front; // 队首指针
    QueueNode* rear;  // 队尾指针
    int size;         // 队列大小
} Queue;

// 初始化队列
void init_queue(Queue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

// 入队操作
void enqueue(Queue* q, int value) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->value = value;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

// 出队操作
int dequeue(Queue* q) {
    if (q->front == NULL) return INT_MIN;
    
    QueueNode* temp = q->front;
    int value = temp->value;
    
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    q->size--;
    return value;
}

// 检查队列是否为空
int is_empty(Queue* q) {
    return q->front == NULL;
}

// 获取数字的指定位数
int get_digit(int number, int exp) {
    return (number / exp) % 10;
}

// 获取数组中最大数的位数
int get_max_digits(int arr[], int n) {
    int max_num = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_num) {
            max_num = arr[i];
        }
    }
    
    int digits = 0;
    while (max_num != 0) {
        digits++;
        max_num /= 10;
    }
    return digits == 0 ? 1 : digits; // 处理全0情况
}

// 基数排序主函数
void radix_sort_queue(int arr[], int n) {
    // 创建10个队列(0-9)
    Queue queues[10];
    for (int i = 0; i < 10; i++) {
        init_queue(&queues[i]);
    }
    
    // 获取最大位数
    int max_digits = get_max_digits(arr, n);
    
    // 按每位进行排序
    for (int exp = 1; max_digits > 0; exp *= 10, max_digits--) {
        // 分配阶段：将数字放入对应队列
        for (int i = 0; i < n; i++) {
            int digit = get_digit(arr[i], exp);
            enqueue(&queues[digit], arr[i]);
        }
        
        // 收集阶段：从队列中取出数字
        int index = 0;
        for (int i = 0; i < 10; i++) {
            while (!is_empty(&queues[i])) {
                arr[index++] = dequeue(&queues[i]);
            }
        }
    }
    
    // 清理队列内存
    for (int i = 0; i < 10; i++) {
        while (!is_empty(&queues[i])) {
            dequeue(&queues[i]);
        }
    }
}

// 测试函数
void test_radix_sort_queue() {
    printf("=== 队列实现的基数排序测试 ===\n");
    
    int arr[] = {329, 457, 657, 839, 436, 720, 355, 93, 100, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("排序前: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    radix_sort_queue(arr, n);
    
    printf("排序后: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    test_radix_sort_queue();
    return 0;
}
