#include<iostream>

using namespace std;
const int N = 1e2 + 10;
int a[N]; 

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i ++){
        a[i] = s[i] - '0';
    }
    bool flage = false;
    int cont = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] == 1){
            cont ++;
        }
    }
    puts(cont < n? "YES" : "NO");
}

int main(){
    int t ;
    cin >> t ;
    while(t --){
        solve();
    }
}