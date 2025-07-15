#include <stdio.h>
#include <stdlib.h>

// 维护堆性质
void heapify(int arr[], int n, int i) {
    int largest = i;        // 初始化最大元素为根节点
    int left = 2 * i + 1;   // 左子节点
    int right = 2 * i + 2;  // 右子节点

    // 如果左子节点大于根节点
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点大于当前最大节点
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大节点不是根节点
    if (largest != i) {
        // 交换根节点和最大节点
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // 递归调整受影响的子树
        heapify(arr, n, largest);
    }
}

// 堆排序主函数
void heap_sort(int arr[], int n) {
    // 构建最大堆（从最后一个非叶子节点开始）
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 逐个提取堆顶元素，开始排序
    for (int i = n - 1; i > 0; i--) {
        // 将当前堆顶元素移动到数组末尾
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 调整剩余元素的堆结构
        heapify(arr, i, 0);
    }
}

// 打印数组
void print_array(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// 测试函数
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前数组: \n");
    print_array(arr, n);

    heap_sort(arr, n);

    printf("排序后数组: \n");
    print_array(arr, n);

    // 测试边界情况
    int arr2[] = {1};
    printf("单元素数组测试: \n");
    heap_sort(arr2, 1);
    print_array(arr2, 1);

    int arr3[] = {};
    printf("空数组测试: \n");
    heap_sort(arr3, 0);
    print_array(arr3, 0);

    return 0;
}
