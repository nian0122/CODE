#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int> > dp(n + 1, vector<int>(n + 1,0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j)dp[i][j] = 0x3f3f3f;
        }
    } 
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        z = min(z,dp[x][y]);
        dp[x][y] = z;
        dp[y][x] = z;
    }
    //Floyd
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); 
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) { 
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
  