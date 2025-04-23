#include <malloc.h>
#include <stdio.h>
typedef int Elemtype;
typedef struct LinkNode{
    Elemtype data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q){
    if(Q.front == Q.rear)
        return true;
    else
        return false;
}

void EnQueue(LinkQueue &Q, Elemtype e){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, Elemtype &e){
    if(Q.front == Q.rear)
        return false;
    LinkNode *q = Q.front->next;
    e = q->data;
    Q.front->next = q->next;
    if(Q.rear == q)
        Q.rear = Q.front;
    free(q);
    return true;
}

int Length(LinkQueue Q){
    int i = 0;
    LinkNode *p = Q.front->next;
    while(p != NULL){
        p = p->next;
        i++;
    }
    return i;
}

int main() {
    LinkQueue Q;
    Elemtype e;  // 注意原代码中定义为Elemtype，这里保持与前面一致（建议统一大小写）

    // 初始化队列测试
    InitQueue(Q);
    printf("初始化后队列是否为空? %s\n", IsEmpty(Q) ? "是" : "否");

    // 入队测试
    EnQueue(Q, 10);
    EnQueue(Q, 20);
    EnQueue(Q, 30);
    printf("插入3个元素后队列长度: %d\n", Length(Q));

    // 出队测试
    DeQueue(Q, e);
    printf("出队元素: %d, 剩余长度: %d\n", e, Length(Q));

    // 连续出队测试
    while (DeQueue(Q, e)) {
        printf("出队元素: %d, 剩余长度: %d\n", e, Length(Q));
    }

    // 空队列出队测试
    printf("尝试空队列出队: %s\n", DeQueue(Q, e) ? "成功" : "失败");

    // 边界条件测试
    EnQueue(Q, 99);
    printf("插入单个元素后队列长度: %d\n", Length(Q));
    DeQueue(Q, e);
    printf("出队后队列是否为空? %s\n", IsEmpty(Q) ? "是" : "否");

    return 0;
}