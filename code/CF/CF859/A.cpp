#include<iostream>

using namespace std;

void solve(){
    int a , b , c ;
    cin >> a >> b >> c;
    if( (a + b) == c){
        cout << '+' << endl;
    }else{
        cout << '-' << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}