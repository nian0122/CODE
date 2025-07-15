/**
 * 基数排序实现(基于计数排序)
 * 算法特点：
 * 1. 非比较排序算法
 * 2. 时间复杂度：O(d*(n+k))，其中d是最大数字的位数，k是基数(10)
 * 3. 空间复杂度：O(n+k)
 * 4. 稳定排序算法
 * 
 * 实现原理：
 * 1. 按数字的每一位进行排序
 * 2. 使用计数排序作为子排序算法
 * 3. 从最低位到最高位依次排序
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 获取数组中最大数的位数
int get_max_digit(int arr[], int n) {
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
    return digits;
}

// 对指定位数进行计数排序
void count_sort(int arr[], int n, int exp) {
    int output[n]; // 输出数组
    int count[10] = {0}; // 计数数组，0-9共10个数字
    
    // 统计每个数字出现的次数
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    
    // 计算累计次数，确认最终位置（前缀和）
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    // 构建输出数组
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; //得到实际存储位置
        count[(arr[i] / exp) % 10]--;
    }
    
    // 将排序结果复制回原数组
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// 基数排序主函数
// 时间复杂度：O(d*(n+k))，其中d是最大数字的位数，k是基数(这里是10)
// 空间复杂度：O(n+k)
void radix_sort(int arr[], int n) {
    // 获取最大数的位数
    int max_digit = get_max_digit(arr, n);
    
    // 从最低位开始，对每一位进行计数排序
    for (int exp = 1; max_digit > 0; exp *= 10, max_digit--) {
        count_sort(arr, n, exp);
    }
}

// 打印数组
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 测试函数
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("排序前: ");
    print_array(arr, n);
    
    radix_sort(arr, n);
    
    printf("排序后: ");
    print_array(arr, n);
    
    return 0;
}
