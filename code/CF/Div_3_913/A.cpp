#include <iostream>
#include <cstring>

using namespace std;
int chr[9],num[9];

void solve() {
    string str;
    cin >> str;
    for(int i = 1; i <= 8; ++i) {
        if(i != str[1] - '0') {
            cout << str[0] << i << '\n';
        }
        if(char('a' + i - 1) != str[0]) {
            cout << char('a' + i - 1) << str[1] << '\n';
        }
    }    

}

int main() {
    int __;
    cin >> __;
    while(__--){
        solve();
    }
}