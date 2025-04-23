#include <malloc.h>
#include <stdio.h>
#define ElemType int
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

bool InitList(LinkList &L){
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    return true;
}

int Length(LinkList L){
    int len=0;
    LNode* p = L->next;
    while(p != NULL){
        p = p->next;
        len++;
    }
    return len;
}

LNode* LocateElem(LinkList L, ElemType e){
    LNode *p = L->next;
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

LNode* GetElem(LinkList L, int i){
    LNode *p = L->next;
    int j = 1;
    while(p != NULL && j < i){
        p = p->next;
        j++;
    }
    return p;
}

bool ListInsert(LinkList &L, int i, ElemType e){
    if (i < 1) return false;
    LNode *p = L;
    int j=1;
    while(p!=NULL && j < i){
        p = p->next;
        j++;
    }
    if(p == NULL)
        return false;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListDelete(LinkList &L, int i, ElemType &e){
    LNode *p = L;
    int j = 0;
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p->next == NULL || j > i-1)
        return false;
    LNode * q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

LinkList List_HeadInsert(LinkList &L){
    LNode *s;
    int x;
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x!=9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

LinkList List_TailInsert(LinkList &L){
    int x;
    L = (LNode*)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while(x != 9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

// 打印链表
void PrintList(LinkList L) {
    LNode* p = L->next;
    while (p != NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// 销毁链表
void DestroyList(LinkList L) {
    LNode* p;
    while (L->next) {
        p = L->next;
        L->next = p->next;
        free(p);
    }
    free(L);
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