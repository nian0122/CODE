/**
 * 双向链表实现文件
 * 实现双向链表的基本操作：初始化、插入、删除、查找等
 * 特点：每个节点包含前驱和后继指针，支持双向遍历
 */

#include <malloc.h>
#include <stdio.h>

#define ElemType int  // 链表元素类型

/**
 * 双向链表节点结构
 * data: 节点存储的数据
 * prior: 指向前驱节点的指针
 * next: 指向后继节点的指针
 */
typedef struct DNode{
    ElemType data;         // 数据域
    struct DNode *prior;    // 前驱指针
    struct DNode *next;     // 后继指针
}DNode, *DLinkList;

/**
 * 初始化双向链表
 * @param L 链表头指针引用
 * @return 初始化成功返回true
 * 时间复杂度: O(1)
 */
bool InitDList(DLinkList &L){
    L = (DNode*)malloc(sizeof(DNode));  // 创建头节点
    L->next = NULL;    // 后继指针初始为空
    L->prior = NULL;   // 前驱指针初始为空
    return true;
}

/**
 * 计算链表长度
 * @param L 链表头指针
 * @return 链表长度(不包含头节点)
 * 时间复杂度: O(n)
 */
int Length(DLinkList L){
    int len = 0;
    DNode* p = L;
    while(p->next != NULL){
        p = p->next;
        len++;
    }
    return len;
}

/**
 * 查找元素位置
 * @param L 链表头指针
 * @param e 待查找元素
 * @return 找到返回节点指针，未找到返回NULL
 * 时间复杂度: O(n)
 */
DNode* LocateElem(DLinkList L, ElemType e){
    DNode* p = L;
    while(p->next != NULL && p->data != e)
        p = p->next;
    return p;
}

/**
 * 获取指定位置的节点
 * @param L 链表头指针
 * @param i 位置(1-based)
 * @return 找到返回节点指针，越界返回NULL
 * 时间复杂度: O(n)
 */
DNode* GetElem(DLinkList L, int i){
    DNode* p = L;
    int j = 0;
    while(p != NULL && j < i){
        p = p->next;
        j++;
    }
    return p;
}

/**
 * 在指定位置插入元素
 * @param L 链表头指针引用
 * @param i 插入位置(1-based)
 * @param e 待插入元素
 * @return 插入成功返回true，失败返回false
 * 时间复杂度: O(n)
 */
bool DListInsert(DLinkList &L, int i, ElemType e){
    if(i < 1) return false;  // 非法位置
    
    DNode *p = L;
    int j = 0;
    // 找到插入位置的前驱节点
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p == NULL) return false;  // 越界
    
    // 创建新节点并初始化数据
    DNode* s = (DNode*)malloc(sizeof(DNode));
    s->data = e;
    
    // 维护后继指针关系
    s->next = p->next;  // 新节点的后继指向原后继
    if(p->next != NULL)
        p->next->prior = s;  // 原后继的前驱指向新节点
    
    // 维护前驱指针关系
    s->prior = p;  // 新节点的前驱指向当前节点
    p->next = s;   // 当前节点的后继指向新节点
    
    return true;
}

/**
 * 删除指定位置的元素
 * @param L 链表头指针引用
 * @param i 删除位置(1-based)
 * @param e 用于返回被删除的元素
 * @return 删除成功返回true，失败返回false
 * 时间复杂度: O(n)
 */
bool DListDelete(DLinkList &L, int i, ElemType &e){
    DNode* p = L;
    int j = 0;
    // 定位到要删除节点的前驱节点
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    // 检查删除位置合法性
    if(p->next == NULL || p == NULL || j > i-1)
        return false;
    
    DNode* q = p->next;  // 要删除的节点
    e = q->data;         // 保存被删除元素
    
    // 维护后继节点的前驱指针
    if(q->next != NULL)
        q->next->prior = p;  // 后继节点的前驱指向当前节点
    
    // 维护前驱节点的后继指针
    p->next = q->next;   // 前驱节点的后继指向被删除节点的后继
    
    free(q);  // 释放节点内存，防止内存泄漏
    return true;
}

/**
 * 正向打印链表
 * @param L 链表头指针
 * 打印每个节点的数据、前驱和后继指针地址
 */
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

/**
 * 反向打印链表
 * @param L 链表头指针
 * 从尾节点向前遍历，验证前驱指针的正确性
 */
void ReversePrint(DLinkList L) {
    DNode* tail = L;
    // 找到尾节点
    while (tail->next != NULL) {
        tail = tail->next;
    }
    
    printf("\n反向链表状态:\n");
    printf("尾节点地址:%p\n", (void*)tail);
    
    printf("反向遍历: ");
    // 从尾节点向前遍历到头节点
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

    // 阶段1: 验证链表初始化是否正确
    printf("===== 阶段1: 初始化测试 =====\n");
    InitDList(L);
    PrintDList(L);  // 应显示空链表
    ReversePrint(L); // 验证反向指针

    // 阶段2: 测试基础插入功能
    printf("\n===== 阶段2: 基础插入测试 =====\n");
    DListInsert(L, 1, 10);   // 首插入
    DListInsert(L, 2, 20);   // 尾插入
    DListInsert(L, 2, 15);   // 中间插入
    PrintDList(L);          // 验证正向指针
    ReversePrint(L);         // 验证反向指针

    // 阶段3: 测试边界条件下的插入
    printf("\n===== 阶段3: 边界插入测试 =====\n");
    printf("插入位置0: %s\n", DListInsert(L, 0, 5) ? "成功" : "失败");  // 应失败
    printf("插入位置5: %s\n", DListInsert(L, 5, 25) ? "成功" : "失败"); // 应成功
    PrintDList(L);
    ReversePrint(L);

    // 阶段4: 测试删除功能
    printf("\n===== 阶段4: 删除测试 =====\n");
    DListDelete(L, 3, e);
    printf("删除第3个元素: %d\n", e);  // 应删除15
    DListDelete(L, 1, e);
    printf("删除第1个元素: %d\n", e);  // 应删除10
    PrintDList(L);
    ReversePrint(L);

    // 阶段5: 测试错误处理能力
    printf("\n===== 阶段5: 异常操作测试 =====\n");
    printf("删除位置0: %s\n", DListDelete(L, 0, e) ? "成功" : "失败");
    printf("删除位置3: %s\n", DListDelete(L, 3, e) ? "成功" : "失败");
    printf("插入位置-1: %s\n", DListInsert(L, -1, 100) ? "成功" : "失败");

    // 阶段6: 验证指针关系的完整性
    printf("\n===== 阶段6: 指针完整性验证 =====\n");
    DNode* first = L->next;
    DNode* last = first->next;
    printf("首节点后继地址: %p 应等于末节点地址: %p\n", 
          (void*)first->next, (void*)last);
    printf("末节点前驱地址: %p 应等于首节点地址: %p\n", 
          (void*)last->prior, (void*)first);

    return 0;
}