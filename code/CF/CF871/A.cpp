#include<iostream>
using namespace std;

void solve(){
    string s;
    string k ="codeforces";
    cin >> s;
    int ans = 0;
    for(int i = 0 ; i< 10 ;i ++){
        if(s[i] != k[i]){
            ans ++;
        }
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t ;
    while(t --){
        solve();
    }
}