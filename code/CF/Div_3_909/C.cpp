#include<iostream>
#include<numeric>
using namespace std;
const int N = 2e5 + 10;
int q[N];

void solve(){
    int n ;
    cin >> n;
    int hh = 1,hh_1 = 1, tt = 2 ;
    int sum_1 = 0;
    for(int i = 1; i <= n; i ++){
        cin >> q[i];
    }
    // for(int i = 1; i <= n; i ++){
    //     cout << q[i];
    // }    
    // cout << endl;
    // while(tt > hh && tt <= n){
    //     int o = q[hh_1] & 1;
    //     int e = q[tt] & 1;
    //     // cout << o << ';' << e << endl;
    //     if(o != e){
    //         tt ++;
    //         hh_1 ++;
    //         // cout << tt << endl;
    //     }
    //     else if(o == e || tt == n + 1){
    //         int a = accumulate(q + hh, q + hh_1, 0);
    //         sum_1 = max(sum_1, a);
    //         hh = tt;
    //         hh_1 = tt;
    //         tt ++;
    //     }
    // }
    int temp = 1;
    bool flage = true;
    for(int i = 1 ;i < n; i ++){
        int o = q[i] & 1;
        int e = q[i + 1] & 1;

        if(o == e || flage){
            flage = false;
            int a = accumulate(q + temp, q + i, 0);
            sum_1 = max(sum_1, a);
            temp = i + 1;
        }
    }
    cout << sum_1 << endl;

}

int main(){
    int t ;
    cin >> t ;
    while(t --){
        solve();
    }
}