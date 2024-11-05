#include<iostream>
#include<algorithm>
#include<cstring>
#include <cstdint>
#define int long long

using namespace std;

const int N = 15e4 + 10;

int n;
int a[N] , c[N];


void add(int x ,int k){
    for (int i = x; i <= n; i += (i & -i)) {
        c[i] += k;
    }
}

int getsum(int x){
    int ans = 0;
    for(int i = x; i > 0; i -= (i & -i)){
        ans += c[i];
    }
    return ans;
}

int32_t main(){
    int t ;
    cin >> t ;
    while(t --){
        cin >> n;
        memset(c,0,N);
        memset(a,0,N);
        int ans = 0;
        for(int i = 1 ;i <= n ; i ++){
            cin >> a[i] ;
            add(i , a[i]);
        }
        for (int i = 1; i <= n ; i++) {
            if(n % i == 0) {
                
                int  MIN = INT64_MAX , MAX = INT64_MIN;
                for(int j = 0 ; j <  n / i; ++j ){
                    MAX = max(MAX , getsum(j * i + i) - getsum(j * i));
                    MIN = min(MIN ,getsum(j * i + i) - getsum(j * i));   
                    // cout << MAX << ';' << MIN << endl;
                }
                // cout << MAX - MIN << endl;
                ans = max(ans , MAX - MIN);
            }
            // cout << endl;
        }
        
        cout << ans << endl;
    }
}