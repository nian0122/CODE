// 快速排序实现
// 使用分治思想，平均时间复杂度O(nlogn)
#include <cstdio>
// 分区函数
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // 选择第一个元素作为基准
    while (low < high) {
        // 从右向左找第一个小于pivot的元素
        while (low < high && arr[high] >= pivot) --high;
        arr[low] = arr[high];
        
        // 从左向右找第一个大于pivot的元素
        while (low < high && arr[low] <= pivot) ++low;
        arr[high] = arr[low];
    }
    arr[low] = pivot; // 基准值放到最终位置
    return low; // 返回基准值位置
}

// 快速排序主函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotPos = partition(arr, low, high); // 分区
        quickSort(arr, low, pivotPos - 1);  // 递归排序左子数组
        quickSort(arr, pivotPos + 1, high); // 递归排序右子数组
    }
}

// 测试用例
int main() {
    int arr[] = {5, 2, 9, 3, 7, 6, 1, 8, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    quickSort(arr, 0, n-1);
    
    // 输出排序结果
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

