// 二分查找实现
#include <iostream>
using namespace std;

// 查找表结构体
typedef struct {
    int* elem;      // 存储空间基址
    int tablelen;   // 表长度
} SSTable;

// 二分查找函数
// 参数：有序表st，查找键值key
// 返回：找到返回元素下标，未找到返回-1
int binary_search(SSTable st, int key) {
    int low = 0; // 搜索区间的左边界
    int high = st.tablelen - 1; // 搜索区间的右边界
    int mid; // 中间位置
    
    // 边界判断说明：
    // 使用low <= high而不是low < high，是为了确保能够检查到最后一个元素
    // 当low == high时，区间内还有一个元素需要检查
    while (low <= high) {
        // 计算中间位置，使用位运算代替除法提高效率
        // 注意：这里使用(low + high) >> 1而不是(low + high) >> 1 +1
        // 因为+1会导致在某些情况下跳过正确的元素
        mid = ((low + high) >> 1); // 等价于(low+high)/2
        
        if (st.elem[mid] == key) {
            return mid; // 找到返回下标
        } else if (st.elem[mid] > key) {
            // 关键边界处理1：
            // 当中间元素大于key时，应该在左半区间继续查找
            // 将high设置为mid-1而不是mid，因为mid已经检查过不匹配
            high = mid - 1; // 在前半部分查找
        } else {
            // 关键边界处理2：
            // 当中间元素小于key时，应该在右半区间继续查找
            // 将low设置为mid+1而不是mid，因为mid已经检查过不匹配
            low = mid + 1;  // 在后半部分查找
        }
    }
    return -1; // 未找到
}

// 测试函数
void test_binary_search() {
    // 测试用例1: 正常查找
    int arr1[] = {1, 3, 5, 7, 9};
    SSTable st1 = {arr1, 5};
    cout << "查找5(存在): " << binary_search(st1, 5) << endl;
    cout << "查找2(不存在): " << binary_search(st1, 2) << endl;

    // 测试用例2: 边界值测试
    cout << "查找第一个元素1: " << binary_search(st1, 1) << endl;
    cout << "查找最后一个元素9: " << binary_search(st1, 9) << endl;

    // 测试用例3: 空表测试
    int emptyArr[] = {};
    SSTable emptySt = {emptyArr, 0};
    cout << "空表查找: " << binary_search(emptySt, 5) << endl;

    // 新增测试用例4: 大数组测试(100个元素)
    const int BIG_SIZE = 100;
    int bigArr[BIG_SIZE];
    for(int i = 0; i < BIG_SIZE; i++) {
        bigArr[i] = i * 2; // 生成0,2,4,...,198的有序数组
    }
    SSTable bigSt = {bigArr, BIG_SIZE};
    cout << "\n大数组测试:\n";
    cout << "查找中间值100: " << binary_search(bigSt, 100) << endl;
    cout << "查找不存在值101: " << binary_search(bigSt, 101) << endl;
    cout << "查找第一个元素0: " << binary_search(bigSt, 0) << endl;
    cout << "查找最后一个元素198: " << binary_search(bigSt, 198) << endl;

    // 新增测试用例5: 重复元素测试
    int dupArr[] = {1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5};
    SSTable dupSt = {dupArr, sizeof(dupArr)/sizeof(dupArr[0])};
    cout << "\n重复元素测试:\n";
    cout << "查找重复元素2: " << binary_search(dupSt, 2) << endl;
    cout << "查找重复元素5: " << binary_search(dupSt, 5) << endl;

    // 新增测试用例6: 全相同元素测试
    int sameArr[] = {7, 7, 7, 7, 7, 7, 7};
    SSTable sameSt = {sameArr, sizeof(sameArr)/sizeof(sameArr[0])};
    cout << "\n全相同元素测试:\n";
    cout << "查找元素7: " << binary_search(sameSt, 7) << endl;
    cout << "查找不存在元素8: " << binary_search(sameSt, 8) << endl;
}

int main() {
    test_binary_search();
    return 0;
}
