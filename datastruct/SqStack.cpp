#define MaxSize 50
#define Elemtype int
typedef struct{
    Elemtype data[MaxSize];
    int top;
}SqStack;


void InitStack(SqStack &S){
    S.top = -1;
}




