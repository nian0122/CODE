#include<string>
#include <iostream>
using namespace std;
typedef string Str;
// 先回退再匹配
void getNext(Str substr, int *next){
    int j=0;
    next[0] = 0;
    for(int i=1; i<substr.length(); i++){
        while(j>0 && substr[i] != substr[j]){
            j=next[j-1];
        }
        if(substr[i] == substr[j]){
            j++;
        }
        next[i]=j;
    }
    //
    // int i = 1;
    // while(i < substr.length()){
    //     if(substr[i] == substr[j]){
    //         next[i] = j+1;
    //         i++;
    //         j++;
    //     }else if(j > 0){
    //         j=next[j-1];
    //     }else{
    //         next[i]=0;
    //         i++;
    //     }
    // }
    //
}

// TODO 
void getNextval(Str substr, int *nextval){
  
    // int m = substr.length();
    // int *next = new int[m];
    // getNext(substr, next);  // 生成前缀函数数组next

    // nextval[0] = 0;  // 传统next数组的next[0]为-1

    // for (int i = 1; i < m; i++) {
    //     int j = next[i-1];  // 传统next数组的next[i] = 前缀函数数组的next[i-1]
    //     if (substr[i] == substr[j]) {
    //         nextval[i] = nextval[j];  // 优化跳转
    //     } else {
    //         nextval[i] = j;  // 直接使用前缀函数值
    //     }
    // }

    // delete[] next;  // 释放临时数组

}

int kmp(Str str, Str substr){
    int* next = new int[substr.length()];
    getNextval(substr,next);
    std::cout << "Next Array: [";
    for(int i = 0; i < substr.length(); i++) {
        std::cout << next[i];
        if(i != substr.length()-1) std::cout << ", ";
    }
    std::cout << "]" << "("<< substr <<")"<<std::endl;
    int i=0, j=0;
    while(i < str.length()){
        if(str[i] == substr[j])
            i++,j++;
        else if(j > 0)
            j = next[j-1];
        else
            i++;
        if (j == substr.length())
            return i - j;     
    }
    // for(i = 0; i<str.length(); i++){
    //     while(j>0 && str[i] != substr[j])
    //         j = next[j-1];
    //     if(str[i] == substr[j])
    //         j++;
    //     if(j == substr.length())
    //         return i-j+1;
    // }
    delete[] next; 
    return -1;
}
void runTest(const string& name, const Str& str, const Str& substr, int expected) {
    int result = kmp(str, substr);
    cout << "测试 [" << name << "]: ";
    cout << "主串: \"" << str << "\" 子串: \"" << substr << "\" ";
    if(result == expected) {
        cout << "\033[32m通过\033[0m (结果: " << result << ")";
    } else {
        cout << "\033[31m失败\033[0m (预期: " << expected << ", 实际: " << result << ")";
    }
    cout << endl;
}

// 显示next数组内容（调试用）
void printNext(const Str& substr) {
    int* next = new int[substr.length()];
    getNextval(substr, next);
    cout << "Next数组: [";
    for(int i=0; i<substr.length(); i++) {
        cout << next[i] << (i < substr.length()-1 ? "," : "");
    }
    cout << "] (\"" << substr << "\")" << endl;
    delete[] next;
}

int main() {
    // 关键功能测试
    runTest("开头匹配", "hello world", "hello", 0);
    runTest("中间匹配", "abxabcabcaby", "abcaby", 6);
    runTest("结尾匹配", "mississippi", "ppi", 8);
    
    // 回溯测试
    runTest("多候选回溯", "ABC ABCDAB ABCDABCDABDE", "ABCDABD", 15);
    
    // 特殊字符测试
    runTest("特殊字符", "a$$$b$$$c", "$b$", 3);
    
    // 重复模式测试
    runTest("重复模式", "AAAAAAA", "AAAA", 0);
    runTest("全重复匹配", "abababab", "abab", 0);

    // 失败案例测试
    runTest("完全失配", "abcdefg", "xyz", -1);
    runTest("部分失配", "abcabd", "abcabc", -1);

    // 边界条件测试
    runTest("空子串", "anything", "", 0);  // 根据代码约定返回0
    runTest("等长匹配", "abcd", "abcd", 0);
    // runTest("超长子串", "apple", "applebee", -1);

    // Next数组验证
    cout << "\nNext数组验证:" << endl;
    printNext("abcaby");     // 预期: [0,0,0,1,2,0]
    printNext("abcdabca");   // 预期: [0,0,0,0,1,2,3,1]
    printNext("aaaaa");      // 预期: [0,1,2,3,4]
    printNext("ababac");     // 预期: [0,0,1,2,3,0]
    printNext("abaabc");
    return 0;
}