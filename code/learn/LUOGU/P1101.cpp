#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
char ch[150][150];
vector<vector<bool>> b(150,vector<bool>(150,false));
vector<vector<bool>> vis(150,vector<bool>(150,false));
string str = " yizhong";
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
vector<pair<int,int>> ans(8);
void dfs(int x, int y, int step, int fx) {
    // cout << x << ' ' << y << '\n';
    if (step>7) {
        for (int i=1; i<=7; i++) {
            b[ans[i].first][ans[i].second] = 1; 
        }
        return;
    }
    int newx = x+dx[fx];
    int newy = y+dy[fx];
    // cout << newx << ' ' << newy << '\n';
    if (newx < 1 || newx > n || newy < 1 || newy > n) return;
    if (vis[newx][newy] == false && ch[newx][newy] == str[step]) {
        ans[step].first = newx;
        ans[step].second = newy;
        vis[newx][newy] = true;
        dfs(newx,newy,step+1,fx);
        ans[step].first = 0;
        ans[step].second = 0;  
        vis[newx][newy] = 0;
    }
}
signed main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> ch[i][j];
        }
    }
    // for (int i=1; i<=n; i++) {
    //     for (int j=1; j<=n; j++) {
    //         cout << ch[i][j];
    //     }
    //     cout << '\n';
    // }
    // cout << str << '\n';
    for (int i=0; i<=n+1; i++) {
        for (int j=0; j<=n+1; j++) {
            for (int k=0; k<8; k++)
            dfs(i,j,1,k);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (b[i][j] == true) cout << ch[i][j];
            else cout << '*';
        }
        cout << '\n';
    }
}