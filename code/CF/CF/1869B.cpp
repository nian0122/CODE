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

void solve()
{
    int n,k,a,b;
    cin >> n >> k >> a >> b;
    vector<int> x(n + 1), y(n + 1);
    for(int i = 1;i <= n ; i++)cin >> x[i] >> y[i];
    int ans = llabs(x[a] - x[b]) + llabs(y[a] - y[b]);
    int mina = LLONG_MAX / 2, minb = LLONG_MAX / 2;
    for (int i = 1 ; i <= k;i ++){
        mina = min(mina , llabs(x[a] - x[i]) + llabs(y[a] - y[i]));
        minb = min(minb , llabs(x[b] - x[i]) + llabs(y[b] - y[i]));
    }
    ans = min(ans , mina + minb);
    cout << ans <<endl;

}

int32_t main(){
    int t;
    cin >> t;
    while(t --)
    solve();
    return 0;
}