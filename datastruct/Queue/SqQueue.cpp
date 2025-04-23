#include <stdio.h>
#define MaxSize 50
typedef int Elemtype;
typedef struct{
    Elemtype data[MaxSize];
    int front, rear;
}SqQueue;

void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;
}

bool isEmpty(SqQueue Q){
    if(Q.front == Q.rear)
        return true;
    else
        return false;
}

bool EnQueue(SqQueue &Q, Elemtype e){
    if((Q.rear+1)%MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, Elemtype &e){
    if(Q.front == Q.rear)
        return false;
    e = Q.data[Q.front];
    Q.front = (Q.front+1) % MaxSize;
    return true;
}

int SizeofQueue(SqQueue Q){
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}

int main() {
    SqQueue Q;
    InitQueue(Q);  // 使用修正后的初始化函数
    
    printf("测试队列初始化:\n");
    printf("队列是否为空？%s\n", isEmpty(Q) ? "是" : "否");
    printf("队列大小：%d\n\n", SizeofQueue(Q));

    // 测试入队
    printf("入队5个元素:\n");
    for (int i = 1; i <= 5; i++) {
        EnQueue(Q, i*10);
        printf("入队元素 %d，当前队列大小：%d\n", i*10, SizeofQueue(Q));
    }

    // 测试出队
    printf("\n出队3个元素:\n");
    Elemtype e;
    for (int i = 0; i < 3; i++) {
        DeQueue(Q, e);
        printf("出队元素 %d，剩余队列大小：%d\n", e, SizeofQueue(Q));
    }

    // 测试循环特性
    printf("\n测试循环特性（入队填满队列）:\n");
    int capacity = MaxSize - 1 - SizeofQueue(Q);  // 队列最大容量为MaxSize-1
    for (int i = 1; i <= capacity; i++) {
        EnQueue(Q, i+100);
    }
    printf("填满后队列大小：%d\n", SizeofQueue(Q));
    printf("尝试超额入队：%s\n\n", EnQueue(Q, 999) ? "成功" : "失败");

    // 测试队列清空
    printf("清空队列:\n");
    while (DeQueue(Q, e)) {
        printf("出队元素 %d\n", e);
    }
    printf("最终队列是否为空？%s\n", isEmpty(Q) ? "是" : "否");
    
    return 0;
}