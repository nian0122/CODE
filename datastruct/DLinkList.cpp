#include <malloc.h>
#include <stdio.h>
#define ElemType int
typedef struct DNode{
    ElemType data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

bool InitDList(DLinkList &L){
    L = (DNode*)malloc(sizeof(DNode));
    L->next = NULL;
    L->prior = NULL;
    return true;
}

int Length(DLinkList L){
    int len = 0;
    DNode* p = L;
    while(p->next != NULL){
        p = p->next;
        len++;
    }
    return len;
}

DNode* LocateElem(DLinkList L, ElemType e){
    DNode* p = L;
    while(p->next != NULL && p->data != e)
        p = p->next;
    return p;
}

DNode* GetElem(DLinkList L, int i){
    DNode* p = L;
    int j = 0;
    while(p != NULL && j < i){
        p = p->next;
        j++;
    }
    return p;
}

bool DListInsert(DLinkList &L, int i, ElemType e){
    if(i < 1) return false;
    DNode *p = L;
    int j = 0;
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p == NULL) return false;
    DNode* s = (DNode*)malloc(sizeof(DNode));
    s->data = e;
    s->next = p->next;
    if(p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

bool DListDelete(DLinkList &L, int i, ElemType &e){
    DNode* p = L;
    int j = 0;
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p->next == NULL || p == NULL || j > i-1)
        return false;
    DNode* q = p->next;
    if(q->next != NULL)
        q->next->prior = p;
    p->next = q->next;
    free(q);
    return true;
}

// 增强版打印函数
void PrintDList(DLinkList L) {
    printf("\n正向链表状态:\n");
    printf("头节点地址:%p\n", (void*)L);
    
    DNode* p = L->next;
    printf("数据节点顺序: ");
    while (p != NULL) {
        printf("[%d|前驱:%p|自身:%p|后继:%p] -> ", 
              p->data, (void*)p->prior, (void*)p, (void*)p->next);
        p = p->next;
    }
    printf("NULL\n");
}

void ReversePrint(DLinkList L) {
    DNode* tail = L;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    
    printf("\n反向链表状态:\n");
    printf("尾节点地址:%p\n", (void*)tail);
    
    printf("反向遍历: ");
    while (tail != L) {
        printf("[%d|前驱:%p|自身:%p|后继:%p] -> ", 
              tail->data, (void*)tail->prior, (void*)tail, (void*)tail->next);
        tail = tail->prior;
    }
    printf("HEAD\n");
}

int main() {
    DLinkList L;
    ElemType e;

    // 初始化验证
    printf("===== 阶段1: 初始化测试 =====\n");
    InitDList(L);
    PrintDList(L);  // 应显示空链表
    ReversePrint(L);

    // 基础插入测试
    printf("\n===== 阶段2: 基础插入测试 =====\n");
    DListInsert(L, 1, 10);   // 首插入
    DListInsert(L, 2, 20);   // 尾插入
    DListInsert(L, 2, 15);   // 中间插入
    PrintDList(L);
    ReversePrint(L);         // 验证反向指针

    // 边界插入测试
    printf("\n===== 阶段3: 边界插入测试 =====\n");
    printf("插入位置0: %s\n", DListInsert(L, 0, 5) ? "成功" : "失败");  // 应失败
    printf("插入位置5: %s\n", DListInsert(L, 5, 25) ? "成功" : "失败"); // 应成功
    PrintDList(L);
    ReversePrint(L);

    // 删除功能测试
    printf("\n===== 阶段4: 删除测试 =====\n");
    DListDelete(L, 3, e);
    printf("删除第3个元素: %d\n", e);  // 应删除15
    DListDelete(L, 1, e);
    printf("删除第1个元素: %d\n", e);  // 应删除10
    PrintDList(L);
    ReversePrint(L);

    // 错误处理测试
    printf("\n===== 阶段5: 异常操作测试 =====\n");
    printf("删除位置0: %s\n", DListDelete(L, 0, e) ? "成功" : "失败");
    printf("删除位置3: %s\n", DListDelete(L, 3, e) ? "成功" : "失败");
    printf("插入位置-1: %s\n", DListInsert(L, -1, 100) ? "成功" : "失败");

    // 指针关系验证
    printf("\n===== 阶段6: 指针完整性验证 =====\n");
    DNode* first = L->next;
    DNode* last = first->next;
    printf("首节点后继地址: %p 应等于末节点地址: %p\n", 
          (void*)first->next, (void*)last);
    printf("末节点前驱地址: %p 应等于首节点地址: %p\n", 
          (void*)last->prior, (void*)first);

    return 0;
}