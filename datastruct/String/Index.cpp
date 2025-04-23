#include <string.h>
#include <stdio.h>
#define MAXLEN 255
typedef struct{
    char ch[MAXLEN];
    int length;
}SString;
int Index(SString S, SString T){
    int i = 0, j = 0;
    while(i < S.length && j < T.length){
        if(S.ch[i] == T.ch[j]){
            ++i,++j;
        }
        else{
            i=i-j+1;  // 如果匹配失败则将 i 移动到上次匹配开始位置的下一个位置
            j=0;
        }
    }
    if(j==T.length) return i-T.length;
    else return 0;
}
int main() {
    // 示例1：成功匹配
    SString S1, T1;
    strncpy(S1.ch, "ABABC", 5);  // 主串：A B A B C
    S1.length = 5;
    strncpy(T1.ch, "ABC", 3);     // 子串：A B C
    T1.length = 3;
    int result1 = Index(S1, T1);
    printf("示例1匹配位置：%d\n", result1); // 输出2

    // 示例2：完全匹配
    SString S2, T2;
    strncpy(S2.ch, "HelloWorld", 10);
    S2.length = 10;
    strncpy(T2.ch, "Hello", 5);
    T2.length = 5;
    int result2 = Index(S2, T2);
    printf("示例2匹配位置：%d\n", result2); // 输出0

    // 示例3：匹配失败
    SString S3, T3;
    strncpy(S3.ch, "ABCDEFG", 7);
    S3.length = 7;
    strncpy(T3.ch, "XYZ", 3);
    T3.length = 3;
    int result3 = Index(S3, T3);
    printf("示例3匹配结果：%d\n", result3); // 输出0

    return 0;
}