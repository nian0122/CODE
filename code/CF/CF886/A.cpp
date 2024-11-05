#include<iostream>

using namespace std;

void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a>b){
        swap(a,b);
    }
    if(b>c){
        swap(b,c);
    }
    if(a>b){
        swap(a,b);
    }
    if(c+b >= 10){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main(){
    int t ;
    cin >> t ;
    while(t -- ){
        solve();
    }
}