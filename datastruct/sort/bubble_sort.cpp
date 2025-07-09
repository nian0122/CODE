/**
 * 冒泡排序算法实现
 * 
 * 算法原理：
 * 重复地遍历要排序的数组，比较相邻的两个元素，如果顺序错误就交换它们。
 * 每次遍历会将当前未排序部分的最大元素"冒泡"到最后。
 * 
 * 优化点：
 * 1. 添加swapped标志，当某次遍历没有发生交换时，说明数组已经有序，可以提前终止
 * 2. 记录最后一次交换位置，减少内层循环次数
 * 
 * 循环次数说明：
 * 外层循环n-1次是因为：
 * - 每次循环确定一个最大元素的位置
 * - n个元素只需要n-1次比较即可完成排序
 * - 最后一个元素无需比较
 * 
 * 时间复杂度分析：
 * - 最坏情况(逆序数组): O(n^2)
 * - 最好情况(已排序数组): O(n)
 * - 平均情况: O(n^2)
 * 
 * 空间复杂度: O(1) (原地排序)
 * 
 * 稳定性: 稳定 (相等元素不会交换)
 */
void bubble_sort(int arr[], int n) {
    int last_swap_pos = n - 1; // 记录最后一次交换位置
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        int current_swap_pos = 0; // 当前轮次最后交换位置
        for (int j = 0; j < last_swap_pos; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
                current_swap_pos = j;
            }
        }
        last_swap_pos = current_swap_pos;
        if (!swapped) break;
    }
}
