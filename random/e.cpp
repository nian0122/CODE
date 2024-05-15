#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll M = 1e9 + 7;
ll maze[510][510];
ll dp[510][510];
void solve() {
    ll n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> maze[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(i == 1 && j == 1) continue;
            if(i == 1) {
                if(maze[1][j] == 1) dp[1][j] == 0;
                else dp[1][j] = dp[1][j - 1];
            } else if(j == 1) {
                if(maze[i][1] == 1) dp[i][1] == 0;
                else dp[i][1] = dp[i - 1][1];
            } else {
                if(maze[i][j] == 1) dp[i][j] == 0;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
            dp[i][j] %= M;
        }
    }
    // for(int i = 1; i <= n; ++i) {
    //     for(int j = 1; j <= m; ++j) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[n][m] << "\n";
}
 
int main()
{
    // solve();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}