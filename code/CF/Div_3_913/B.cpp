#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <typeinfo>

using namespace std;

void solve() {
    stack <int> low, up;
    string ans;
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0;i < n; i++) {
        if(s[i] >= 'a' && s[i] <='z' && s[i] != 'b' && s[i] != 'B') {
            low.push(i);
        }else if(s[i] >= 'A' && s[i] <='Z' && s[i] != 'b' && s[i] != 'B') {
            up.push(i);
        }
        if(s[i] == 'b' && !low.empty()) {
            low.pop();
        }
        if(s[i] == 'B' && !up.empty()) {
            up.pop();
        }
    }
    int ans_lenth = low.size() + up.size();
    // cout << low.size() << ' ' << ans_lenth << endl;
    // while (!low.empty()) {
    //     cout << int(low.top()) << ' ';
    //     low.pop();
    // }
    // cout << endl;
    // while (!up.empty()) {
    //     cout << int(up.top()) << ' ';
    //     up.pop();
    // }
    // cout << endl;    
    // cout << typeid(low.top()).name() << endl;
    vector<int> index;
    while (!low.empty()) {
        index.push_back(low.top());
        low.pop();
    }
    while (!up.empty()) {
        index.push_back(up.top());
        up.pop();
    }
    sort(index.begin(), index.end());
    // cout << ans_lenth << " " << index.size() << endl;
    // for(auto it : index) {
    //     cout << it << endl;
    // }    
    for(auto it : index) {
        ans += s[it];
    }
    cout << ans << endl;
}

int main() {
    int __;
    cin >> __;
    while (__--) {
        solve();
    }
    return 0;
}