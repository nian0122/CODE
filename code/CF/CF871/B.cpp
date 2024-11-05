#include<iostream>

using namespace std;

void solve(){
    int n ;
    cin >> n;
    int tt = 0 ,hh = 0;
    int ans = 0;
    bool flage = true;
    int a;
    for(int i = 0 ;i < n ;i ++){
        cin >> a ;
        if(!a){
            hh ++;
        }
        else{
            flage = false;
            ans = max( ans ,hh -tt);
            tt = hh;
        }
    }
    if(flage){
        ans = hh - tt;
    }
    if(!a){
        ans = max( ans ,hh - tt);
    }
    cout << ans << endl;
}

int main(){
    int t ;
    cin >> t;
    while(t --){
        solve();
    }
}