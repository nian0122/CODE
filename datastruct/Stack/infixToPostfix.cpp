#include <stack>
#include <string>
#include <iostream>
using namespace std;

// 声明辅助函数
int precedence(char op);

// 中缀转后缀核心函数
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;
    
    for(char c : infix) {
        if(c >= 'A' && c <= 'Z') {
            postfix += c;  // 操作数直接输出
        }
        else if(c == '(') {
            operators.push(c);  // 左括号入栈
        }
        else if(c == ')') {
            // 弹出直到左括号
            while(!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();  // 丢弃左括号
        }
        else {
            // 处理运算符优先级
            while(!operators.empty() && 
                 precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }
    
    // 弹出剩余运算符
    while(!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }
    
    return postfix;
}

// 运算符优先级实现
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;  // 括号
}

int main() {
    string input = "A+B*(C-D)-E/F";
    
    cout << "中缀表达式: " << input << endl;
    cout << "后缀表达式: " << infixToPostfix(input) << endl;
    // 输出: ABCD-*+EF/-
    
    // 测试用例
    cout << "\n更多测试：" << endl;
    cout << "A+B*C    => " << infixToPostfix("A+B*C") << endl;      // ABC*+
    cout << "(A+B)*C  => " << infixToPostfix("(A+B)*C") << endl;    // AB+C*
    cout << "A+B+C    => " << infixToPostfix("A+B+C") << endl;      // AB+C+
    
    return 0;
}
