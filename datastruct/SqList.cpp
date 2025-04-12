#include <malloc.h>
#include <stdio.h>
#define InitSize 100
#define ElemType int
typedef struct{
    ElemType* data;
    int length;
    int maxsize;
}SqList;

void InitList(SqList &L){
    L.data = (ElemType *)malloc(InitSize*sizeof(ElemType));
    L.length = 0;
    L.maxsize = InitSize;
}

bool ListInsert(SqList &L, int i, ElemType e){
    if(i < 1 || i > L.length+1)
        return false;
    if(L.length >= L.maxsize)
        return false;
    for(int j=L.length; j >= i; j--)
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, ElemType &e){
    if(i < 1 || i > L.length)
        return false;
    e = L.data[i-1];
    for(int j = i; j < L.length; j++)
    L.data[j-1] = L.data[j];
    L.length--;
    return true;
}

int LocateElem(SqList &L, ElemType e){
    int i;
    for(i=0; i < L.length; i++)
        if(L.data[i] == e)
            return i+1;
    return 0;
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