#include<iostream>

using namespace std;

void solve(){
    int n ;
    cin >> n;
    // cout << n << endl;
    if(n % 3 == 0){
        cout << "Second" << endl;
    }
    else if(n % 3 == 1 || n % 3 == 2){
        cout << "First" << endl;
    }
}

int main(){
    int t ;
    cin >> t ;
    while(t --){
        solve();
    }
}