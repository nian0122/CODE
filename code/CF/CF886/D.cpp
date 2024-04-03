#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 2e5 + 10;
int num[N],ans[N];

void solve(){
    int n,k;
    cin >> n >> k;
    memset(num , 0 , N);
    memset(ans,0,N);
    int tt = 0 ,hh = 0;
    for(int i = 0 ; i < n;i ++ ){
        cin >> num[i];
    } 
    // for(auto i : num){
    //     cout << i << " ";
    // }
    // cout << endl;
    sort(num,num+n);
    int p = 0;
    for(int i = 1 ; i <= n ;i ++){
        if(abs(num[i] - num[i - 1] ) <= k){
            hh++;
            // cout <<i << ":"  << hh << ':' << tt <<' '<< num[i]<<' ' << num[i-1]<< endl;
        }
        else{
            hh ++;
            ans[p ++] = hh - tt;
            tt = hh;
            // cout <<i << ":" << ans[p-1] << " :" << hh<< endl;
            
        }
        
    }
    sort(ans,ans+p);
    int sum = 0;
    for(int i = 0 ; i < p - 1 ;i ++ ){
        sum += ans[i];
    }
    cout << sum << endl;
}

int main(){
    int t;
    cin >> t ;
    while(t --){
        solve();
    }
}