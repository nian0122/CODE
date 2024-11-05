#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<vector>
#define endl '\n'
#define int long long
using namespace std;
const int N = 1e5 + 10;
int a[N] , b[N];

void solve()
{
    int n, m , k ;
    cin >> n >> m >> k;
    k -- ;
    for(int i = 0 ; i < n ; i ++) cin >> a[i];
    for(int i = 0 ; i < m ; i ++) cin >> b[i];
    int x = 0 , y = 0;
    sort(a , a + n);sort(b , b + m);
    if(b[m - 1] > a [0]) swap(a[0] ,b[m - 1]);
    sort(a , a + n);sort(b , b + m);
    if(k & 1){
        swap(a[n - 1], b[0]);
    }
    long long ans = 0;
	for(int i = 0 ; i < n ; i ++) ans += a[i];
	printf("%lld\n", ans);
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t --)
    solve();
    return 0;
}