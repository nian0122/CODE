//核心是选择未排序数列中最小的数
#include <stdio.h>

// 函数注释
// 功能：选择排序
// 参数：arr - 待排序的数组，n - 数组长度
// 返回值：无
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // 假设当前i位置为最小值的索引
        int min_index = i;
        // 在未排序部分中找到一个比当前最小值更小的数
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // 如果找到的最小值不是当前位置，则进行交换
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}
