/**
 * 顺序表实现文件
 * 实现顺序表的基本操作：初始化、插入、删除、查找等
 * 采用动态分配内存方式，支持自动扩容
 */

#include <malloc.h>
#include <stdio.h>

#define InitSize 100  // 顺序表初始容量
#define ElemType int  // 顺序表元素类型

/**
 * 顺序表结构体
 * data: 指向存储元素的数组指针
 * length: 当前顺序表长度
 * maxsize: 顺序表最大容量
 */
typedef struct{
    ElemType* data;  // 存储数组基地址
    int length;      // 当前长度
    int maxsize;     // 最大容量
}SqList;

/**
 * 初始化顺序表
 * @param L 顺序表引用
 * 时间复杂度: O(1)
 */
void InitList(SqList &L){
    L.data = (ElemType *)malloc(InitSize*sizeof(ElemType));  // 分配初始内存
    L.length = 0;       // 初始长度为0
    L.maxsize = InitSize; // 设置最大容量
}

/**
 * 在顺序表指定位置插入元素
 * @param L 顺序表引用
 * @param i 插入位置(1-based)
 * @param e 待插入元素
 * @return 插入成功返回true，失败返回false
 * 时间复杂度: O(n)
 */
bool ListInsert(SqList &L, int i, ElemType e){
    // 检查位置合法性
    if(i < 1 || i > L.length+1)
        return false;
    // 检查表是否已满
    if(L.length >= L.maxsize)
        return false;
    
    // 从后向前移动元素，为新元素腾出位置
    for(int j=L.length; j >= i; j--)
        L.data[j] = L.data[j-1];
    
    L.data[i-1] = e;  // 插入新元素
    L.length++;       // 长度增加
    return true;
}

/**
 * 删除顺序表指定位置的元素
 * @param L 顺序表引用
 * @param i 删除位置(1-based)
 * @param e 用于返回被删除的元素
 * @return 删除成功返回true，失败返回false
 * 时间复杂度: O(n)
 */
bool ListDelete(SqList &L, int i, ElemType &e){
    // 检查位置合法性
    if(i < 1 || i > L.length)
        return false;
    
    e = L.data[i-1];  // 保存被删除元素
    
    // 从前向后移动元素，覆盖被删除元素
    for(int j = i; j < L.length; j++)
        L.data[j-1] = L.data[j];
    
    L.length--;  // 长度减少
    return true;
}

/**
 * 查找元素在顺序表中的位置
 * @param L 顺序表引用
 * @param e 待查找元素
 * @return 找到返回位置(1-based)，未找到返回0
 * 时间复杂度: O(n)
 */
int LocateElem(SqList &L, ElemType e){
    // 顺序查找
    for(int i=0; i < L.length; i++)
        if(L.data[i] == e)
            return i+1;  // 返回1-based位置
    return 0;  // 未找到
}

int main() {
    SqList L;
    ElemType e;

    // 初始化测试
    InitList(L);
    printf("初始化测试:\n");
    printf("长度: %d (应为0)\n", L.length);
    printf("容量: %d (应为%d)\n", L.maxsize, InitSize);
    printf("数据指针: %s\n\n", L.data ? "非空" : "空");

    // 插入测试
    printf("插入测试:\n");
    printf("插入位置1(5): %s\n", ListInsert(L, 1, 5) ? "成功" : "失败");
    printf("当前长度: %d (应为1)\n", L.length);
    printf("插入位置2(10): %s\n", ListInsert(L, 2, 10) ? "成功" : "失败");
    printf("当前长度: %d (应为2)\n", L.length);
    printf("插入位置1(3): %s\n", ListInsert(L, 1, 3) ? "成功" : "失败");
    printf("当前长度: %d (应为3)\n", L.length);
    printf("数组内容: [%d, %d, %d] (应为[3,5,10])\n\n", L.data[0], L.data[1], L.data[2]);

    // 非法插入测试
    printf("非法插入测试:\n");
    printf("插入位置0: %s\n", ListInsert(L, 0, 100) ? "成功" : "失败");
    printf("插入位置5: %s\n\n", ListInsert(L, 5, 100) ? "成功" : "失败");

    // 边界插入
    printf("边界插入测试:\n");
    printf("插入位置4(15): %s\n", ListInsert(L, 4, 15) ? "成功" : "失败");
    printf("当前长度: %d (应为4)\n", L.length);
    printf("数组内容: [%d, %d, %d, %d]\n\n", L.data[0], L.data[1], L.data[2], L.data[3]);

    // 删除测试
    printf("删除测试:\n");
    printf("删除位置2: %s\n", ListDelete(L, 2, e) ? "成功" : "失败");
    printf("删除元素: %d (应为5)\n", e);
    printf("当前长度: %d (应为3)\n", L.length);
    printf("数组内容: [%d, %d, %d]\n", L.data[0], L.data[1], L.data[2]);

    // 非法删除
    printf("\n非法删除测试:\n");
    printf("删除位置0: %s\n", ListDelete(L, 0, e) ? "成功" : "失败");
    printf("删除位置4: %s\n\n", ListDelete(L, 4, e) ? "成功" : "失败");

    // 查找测试
    printf("查找测试:\n");
    printf("查找10的位置: %d (应为2)\n", LocateElem(L, 10));
    printf("查找3的位置: %d (应为1)\n", LocateElem(L, 3));
    printf("查找999的位置: %d (应为0)\n\n", LocateElem(L, 999));

    // 满表测试
    printf("填满顺序表测试:\n");
    while (ListInsert(L, L.length+1, 0)); // 持续插入直到满
    printf("最终长度: %d (应达%d)\n", L.length, L.maxsize);
    printf("插入第101个元素: %s\n", ListInsert(L, 101, 0) ? "成功" : "失败");

    return 0;
}