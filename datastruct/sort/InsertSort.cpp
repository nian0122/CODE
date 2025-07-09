// 插入排序实现
// 使用A[0]作为哨兵位置
typedef int Elemtype;

void InsertSort(Elemtype A[], int n) {
    int i,j;
    // 从第二个元素开始排序
    for(i=2; i <= n; i++) {
        // 如果当前元素小于前一个元素，需要插入
        if(A[i] < A[i-1]) {
            A[0]=A[i]; // 设置哨兵
            // 向后移动比哨兵大的元素
            for(j=i-1; A[0] < A[j]; --j)
                A[j+1]=A[j];
            // 插入哨兵元素到正确位置
            A[j+1]=A[0];
        }
    }
}

// 测试用例
#include <iostream>
using namespace std;

void printArray(Elemtype A[], int n) {
    for (int i = 1; i <= n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    // 测试用例1: 普通情况
    Elemtype arr1[] = {0, 5, 2, 4, 6, 1, 3}; // A[0]是哨兵
    int n1 = sizeof(arr1)/sizeof(arr1[0]) - 1;
    cout << "排序前: ";
    printArray(arr1, n1);
    InsertSort(arr1, n1);
    cout << "排序后: ";
    printArray(arr1, n1);

    // 测试用例2: 已排序数组
    Elemtype arr2[] = {0, 1, 2, 3, 4, 5};
    int n2 = sizeof(arr2)/sizeof(arr2[0]) - 1;
    cout << "\n排序前: ";
    printArray(arr2, n2);
    InsertSort(arr2, n2);
    cout << "排序后: ";
    printArray(arr2, n2);

    // 测试用例3: 逆序数组
    Elemtype arr3[] = {0, 5, 4, 3, 2, 1};
    int n3 = sizeof(arr3)/sizeof(arr3[0]) - 1;
    cout << "\n排序前: ";
    printArray(arr3, n3);
    InsertSort(arr3, n3);
    cout << "排序后: ";
    printArray(arr3, n3);

    return 0;
}
