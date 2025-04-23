#define Elemtype int
#include "malloc.h"
#include <stdio.h>
typedef struct Linknode{
    Elemtype data;
    struct Linknode *next;
}Linknode, *LiStack;

void InitStack(LiStack &L){
    L = (Linknode *)malloc(sizeof(Linknode));
    L->next = NULL;
}

bool StackEmpty(LiStack L){
    if(L->next == NULL)
        return true;
    else
        return false;
}

bool Push(LiStack &L, Elemtype e){
    Linknode *s = (Linknode *)malloc(sizeof(Linknode));
    s->data = e;
    s->next = L->next;
    L->next = s;
    return true;   
}

bool Pop(LiStack &L, Elemtype &e){
    if(L->next == NULL)
        return false;
    Linknode* q = L->next;
    e = q->data;
    L->next = q->next;
    free(q);
    return true;
}

bool GetTop(LiStack L, Elemtype &e){
    if(L->next == NULL)
        return false;
    e = L->next->data;
    return true;
}

int main() {
    LiStack stack;
    Elemtype e; // 用于接收栈元素

    // 测试初始化
    InitStack(stack);
    printf("初始化后栈是否为空? %s\n", StackEmpty(stack) ? "是" : "否");  // 预期输出"是"

    // 测试入栈
    Push(stack, 10);
    Push(stack, 20);
    Push(stack, 30);
    printf("入栈10,20,30后栈是否为空? %s\n", StackEmpty(stack) ? "是" : "否"); // 预期输出"否"

    // 测试获取栈顶
    GetTop(stack, e);
    printf("当前栈顶元素: %d\n", e); // 预期输出30

    // 测试出栈
    Pop(stack, e);
    printf("第一次出栈元素: %d\n", e); // 预期输出30
    Pop(stack, e);
    printf("第二次出栈元素: %d\n", e); // 预期输出20

    // 测试中间状态
    GetTop(stack, e);
    printf("当前栈顶元素: %d\n", e); // 预期输出10
    printf("出栈两次后栈是否为空? %s\n", StackEmpty(stack) ? "是" : "否"); // 预期输出"否"

    // 测试清空栈
    Pop(stack, e);
    printf("第三次出栈元素: %d\n", e); // 预期输出10
    printf("清空后栈是否为空? %s\n", StackEmpty(stack) ? "是" : "否"); // 预期输出"是"

    // 测试空栈出报错
    if(!Pop(stack, e)) {
        printf("空栈出栈失败测试通过\n"); // 预期执行
    }

    return 0;
}