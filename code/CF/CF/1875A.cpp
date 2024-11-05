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
    int a,b,n;cin >> a >> b >> n;
    vector<int> tool(n + 1);
    for(int i = 1;i <= n;i ++)cin >> tool[i];
    sort(tool.begin(),tool.end());
    int ans = b;
    for(int i = 1; i <= n; i ++)
    {

            // cout << temp << ":";
            ans += min(tool[i],a - 1);
            // cout << temp << endl;
        
        
    }
    cout << ans   << endl; 
    
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t --)
    solve();
    return 0;
}