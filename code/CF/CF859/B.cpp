#include<iostream>
#include<algorithm>
#include<cstring>
#include<numeric>
#include<functional>

using namespace std;
const int N = 110;
int a[N],b[N],c[N];

void solve(){
    int n ; 
    cin >> n;
    int odd = 0 ,eve = 0; 
    for(int i = 0;i < n; i ++ ){
        cin >> a[i] ;
        if(a[i] & 1){
            odd ++;
            b[odd] = a[i];
        }else{
            eve ++;
            c[eve] = a[i];
        }
    }
    int sum_1 = accumulate(b + 1 , b + 1 + odd , 0 );
    int sum_2 = accumulate(c + 1 , c + 1 + eve , 0 );
    // cout << sum_1 << ';' << sum_2 << endl;
    if(sum_2 > sum_1 ){
        cout << "YES" << endl;
    }else{
        cout << "No" << endl;
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