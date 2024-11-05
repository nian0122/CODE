#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, ans, t="";
    cin >> s;
    ans = s;
    int tot = 0;
    vector<int> x(n, -1);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] == 'b' || s[i] == 'c' || s[i] == 'd'){
            s[i] = 'C';
        }else {
            s[i] = 'V';
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << s[i];
    // }
    // cout << endl;
    for(int i=0; i<s.size(); i++) {
	    t += s[i];
	    if((t == "CV" || t == "CVC") && (s[i+1] == 'C' && s[i+2] == 'V'))
             x[tot++] = i, t = "";
    }
    //     for (int i = 0; i < n; i++) {
    //     cout << x[i];
    // }
    for(int i = 0, j = 0; i < n; i++) {
        cout << ans[i];
        if(i == x[j]){
            j++;
            cout << '.';
        }
    }
    cout <<endl;
    
}

int main () {
    int __;
    cin >> __;
    while(__--) {
        solve();
    }
}