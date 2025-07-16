/**
 * 单链表实现文件
 * 实现单链表的基本操作：初始化、插入、删除、查找等
 * 包含头插法和尾插法创建链表
 */

#include <malloc.h>
#include <stdio.h>

#define ElemType int  // 链表元素类型

/**
 * 单链表节点结构
 * data: 存储数据元素
 * next: 指向下一个节点的指针
 */
typedef struct LNode{
    ElemType data;      // 数据域
    struct LNode *next; // 指针域
}LNode, *LinkList;      // LinkList为指向头节点的指针

/**
 * 初始化单链表
 * @param L 链表头指针引用
 * @return 初始化成功返回true
 * 时间复杂度: O(1)
 */
bool InitList(LinkList &L){
    L = (LNode*)malloc(sizeof(LNode)); // 创建头节点
    L->next = NULL;                   // 初始为空链表
    return true;
}

/**
 * 获取链表长度
 * @param L 链表头指针
 * @return 链表长度（不包含头节点）
 * 时间复杂度: O(n)
 */
int Length(LinkList L){
    int len=0;
    LNode* p = L->next;  // 从首元节点开始
    while(p != NULL){
        p = p->next;
        len++;
    }
    return len;
}

/**
 * 按值查找节点
 * @param L 链表头指针
 * @param e 要查找的元素值
 * @return 找到返回节点指针，未找到返回NULL
 * 时间复杂度: O(n)
 */
LNode* LocateElem(LinkList L, ElemType e){
    LNode *p = L->next;  // 从首元节点开始查找
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

/**
 * 按序号查找节点
 * @param L 链表头指针
 * @param i 节点序号(从1开始)
 * @return 找到返回节点指针，未找到返回NULL
 * 时间复杂度: O(n)
 */
LNode* GetElem(LinkList L, int i){
    LNode *p = L->next;  // 从首元节点开始
    int j = 1;           // 计数器
    while(p != NULL && j < i){
        p = p->next;
        j++;
    }
    return p;
}

/**
 * 在指定位置插入节点
 * @param L 链表头指针引用
 * @param i 插入位置(1-based)
 * @param e 插入元素值
 * @return 插入成功返回true，失败返回false
 * 时间复杂度: O(n)
 */
bool ListInsert(LinkList &L, int i, ElemType e){
    if (i < 1) return false;  // 位置非法
    LNode *p = L;            // 从头节点开始
    int j=1;                 // 计数器
    // 找到第i-1个节点
    while(p!=NULL && j < i){
        p = p->next;
        j++;
    }
    if(p == NULL)  // 位置超出链表长度
        return false;
    // 创建新节点并插入
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

/**
 * 删除指定位置节点
 * @param L 链表头指针引用
 * @param i 删除位置(1-based)
 * @param e 用于返回被删除元素值
 * @return 删除成功返回true，失败返回false
 * 时间复杂度: O(n)
 */
bool ListDelete(LinkList &L, int i, ElemType &e){
    LNode *p = L;          // 从头节点开始
    int j = 0;             // 计数器
    // 找到第i-1个节点
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    // 检查位置合法性
    if(p->next == NULL || j > i-1)
        return false;
    // 删除节点并释放内存
    LNode * q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

/**
 * 头插法创建链表
 * @param L 链表头指针引用
 * @return 创建好的链表
 * 时间复杂度: O(n)
 * 注意: 输入以9999结束
 */
LinkList List_HeadInsert(LinkList &L){
    LNode *s;
    int x;
    L = (LNode*)malloc(sizeof(LNode));  // 创建头节点
    L->next = NULL;                     // 初始为空链表
    scanf("%d", &x);
    while (x!=9999){  // 9999为结束标志
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;  // 新节点插入到链表头部
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

/**
 * 尾插法创建链表
 * @param L 链表头指针引用
 * @return 创建好的链表
 * 时间复杂度: O(n)
 * 注意: 输入以9999结束
 */
LinkList List_TailInsert(LinkList &L){
    int x;
    L = (LNode*)malloc(sizeof(LNode));  // 创建头节点
    LNode *s, *r = L;                  // r始终指向尾节点
    scanf("%d", &x);
    while(x != 9999){  // 9999为结束标志
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;   // 新节点链接到尾节点后面
        r = s;         // 更新尾节点指针
        scanf("%d", &x);
    }
    r->next = NULL;    // 尾节点指针置空
    return L;
}

/**
 * 打印链表
 * @param L 链表头指针
 * 时间复杂度: O(n)
 */
void PrintList(LinkList L) {
    LNode* p = L->next;  // 从首元节点开始
    while (p != NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");  // 链表结束标志
}

/**
 * 销毁链表
 * @param L 链表头指针
 * 时间复杂度: O(n)
 */
void DestroyList(LinkList L) {
    LNode* p;
    while (L->next) {  // 释放所有数据节点
        p = L->next;
        L->next = p->next;
        free(p);
    }
    free(L);  // 释放头节点
}

int main() {
    LinkList L;
    ElemType e;

    // 初始化测试
    printf("----- 初始化测试 -----\n");
    InitList(L);
    printf("头节点地址: %p (应非空)\n", (void*)L);
    printf("初始长度: %d (应为0)\n", Length(L));

    // 插入测试
    printf("\n----- 插入测试 -----\n");
    ListInsert(L, 1, 10);  // 首插
    ListInsert(L, 2, 30);  // 尾插
    ListInsert(L, 2, 20);  // 中插
    printf("链表内容：");
    PrintList(L);  // 应输出10->20->30->NULL
    printf("当前长度: %d (应为3)\n", Length(L));

    // 非法插入测试
    printf("\n----- 非法插入测试 -----\n");
    bool ret1 = ListInsert(L, 5, 40);  // 超范围
    bool ret2 = ListInsert(L, 0, 0);   // 非法位置
    printf("插入位置5结果: %d (应为0)\n", ret1);
    printf("插入位置0结果: %d (应为0)\n", ret2);

    // 查找测试
    printf("\n----- 查找测试 -----\n");
    LNode* p1 = GetElem(L, 2);
    printf("第2个元素: %d (应为20)\n", p1 ? p1->data : -1);
    LNode* p2 = LocateElem(L, 30);
    printf("查找30结果: %d (应为非0)\n", p2 != NULL);

    // 删除测试
    printf("\n----- 删除测试 -----\n");
    ListDelete(L, 2, e);
    printf("删除元素: %d (应为20)\n", e);
    printf("删除后链表: ");
    PrintList(L);  // 应输出10->30->NULL
    printf("当前长度: %d (应为2)\n", Length(L));

    // 头插法测试
    printf("\n----- 头插法测试 -----\n");
    printf("输入测试数据(用空格分隔，以9999结束): ");
    List_HeadInsert(L);
    printf("头插结果：");
    PrintList(L);  // 输入1 2 3 9999应输出3->2->1->NULL

    // 尾插法测试
    printf("\n----- 尾插法测试 -----\n");
    printf("输入测试数据(用空格分隔，以9999结束): ");
    List_TailInsert(L);
    printf("尾插结果：");
    PrintList(L);  // 输入4 5 6 9999应输出4->5->6->NULL

    DestroyList(L);
    return 0;
}