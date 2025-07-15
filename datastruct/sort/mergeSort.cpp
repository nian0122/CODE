#include <iostream>
#include <cstring>
using namespace std;

/**
 * 合并两个已排序的子数组
 * @param input_array 输入数组
 * @param temp_array 临时数组
 * @param start_index 起始索引
 * @param middle_index 中间索引
 * @param end_index 结束索引
 */
static void merge(int input_array[], int temp_array[], int start_index, int middle_index, int end_index) {
    int left_index, right_index, merged_index;
    
    // 将元素复制到临时数组
    for (merged_index = start_index; merged_index <= end_index; merged_index++) {
        temp_array[merged_index] = input_array[merged_index];
    }
    
    // 合并两个已排序的子数组
    for (left_index = start_index, right_index = middle_index + 1, merged_index = left_index; 
         left_index <= middle_index && right_index <= end_index; merged_index++) {
        // 比较左右子数组元素，取较小者放入原数组
        if (temp_array[left_index] < temp_array[right_index]) {
            input_array[merged_index] = temp_array[left_index++];
        } else {
            input_array[merged_index] = temp_array[right_index++];
        }
    }
    
    // 复制左子数组剩余元素
    while (left_index <= middle_index) {
        input_array[merged_index++] = temp_array[left_index++];
    }
    
    // 复制右子数组剩余元素
    while (right_index <= end_index) {
        input_array[merged_index++] = temp_array[right_index++];
    }
}

/**
 * 递归实现归并排序
 * @param input_array 输入数组
 * @param temp_array 临时数组
 * @param start_index 起始索引
 * @param end_index 结束索引
 */
static void merge_sort_recursive(int input_array[], int temp_array[], int start_index, int end_index) {
    if (start_index < end_index) {
        // 计算中间索引
        int middle_index = (start_index + end_index) >> 1;
        // 递归排序左半部分
        merge_sort_recursive(input_array, temp_array, start_index, middle_index);
        // 递归排序右半部分
        merge_sort_recursive(input_array, temp_array, middle_index + 1, end_index);
        // 合并已排序的两部分
        merge(input_array, temp_array, start_index, middle_index, end_index);
    }
}

/**
 * 归并排序对外接口
 * @param input_array 待排序数组
 * @param array_size 数组大小
 */
void merge_sort(int input_array[], int array_size) {
    if (array_size <= 1) return;
    
    // 分配临时数组空间
    int* temp_array = new int[array_size];
    // 执行归并排序
    merge_sort_recursive(input_array, temp_array, 0, array_size - 1);
    // 释放临时数组空间
    delete[] temp_array;
}

/**
 * 测试归并排序函数
 */
void test_merge_sort() {
    const int array_size = 10;
    int numbers_array[array_size] = {5, 2, 9, 1, 5, 6, 3, 8, 4, 7};
    
    cout << "原始数组: ";
    for (int index = 0; index < array_size; index++) {
        cout << numbers_array[index] << " ";
    }
    cout << endl;
    
    merge_sort(numbers_array, array_size);
    
    cout << "排序后数组: ";
    for (int index = 0; index < array_size; index++) {
        cout << numbers_array[index] << " ";
    }
    cout << endl;
}

int main() {
    test_merge_sort();
    return 0;
}
