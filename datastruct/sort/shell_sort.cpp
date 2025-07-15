/**
 * 希尔排序实现
 * 时间复杂度: O(n^1.3) 到 O(n^2)
 * 空间复杂度: O(1)
 */
#include <cstdio>
void shellSort(int arr[], int n) {
    // 初始间隔设为数组长度的一半，然后逐步缩小
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 对当前间隔大小的子序列进行插入排序
        for (int i = gap; i < n; i++) {
            // 保存当前元素值并在原位置留出空位
            int temp = arr[i];
            int j;
            
            // 将比当前元素大的元素向后移动，直到找到合适的位置
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            
            // 将原元素放入正确的位置
            arr[j] = temp;
        }
    }
}

// 测试希尔排序
int main() {
    // 测试用例1：普通数组
    int arr1[] = {12, 34, 54, 2, 3};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    shellSort(arr1, n1);
    printf("测试用例1排序结果: ");
    for (int i = 0; i < n1; i++)
        printf("%d ", arr1[i]);
    printf("\n");

    // 测试用例2：已排序数组
    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    shellSort(arr2, n2);
    printf("测试用例2排序结果: ");
    for (int i = 0; i < n2; i++)
        printf("%d ", arr2[i]);
    printf("\n");

    // 测试用例3：逆序数组
    int arr3[] = {5, 4, 3, 2, 1};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    shellSort(arr3, n3);
    printf("测试用例3排序结果: ");
    for (int i = 0; i < n3; i++)
        printf("%d ", arr3[i]);
    printf("\n");

    // 测试用例4：单元素数组
    int arr4[] = {42};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    shellSort(arr4, n4);
    printf("测试用例4排序结果: ");
    for (int i = 0; i < n4; i++)
        printf("%d ", arr4[i]);
    printf("\n");

    return 0;
}