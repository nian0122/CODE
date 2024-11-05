#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<vector>
#define endl '\n'
//#define int long long
#define all(a) (a).begin(),(a).end()
#define sz(a) (a).size()
using namespace std;
const int N = 1e3 + 10;
int n,m;
bool vis[N][N];
int a[N][N];

int dfs(int i,int j){
    vis[i][j] = true;
    int ans = a[i][j];
    if(i > 0 && !vis[i-1][j] && a[i-1][j] ){
        ans += dfs(i-1,j);
    }
    if(i < n && !vis[i+1][j] && a[i+1][j]){
        ans += dfs(i+1,j);
    }
    if(j >0 && !vis[i][j-1] && a[i][j-1]){
        ans += dfs(i,j-1);
    }
    if(j < m && !vis[i][j+1] && a[i][j+1]){
        ans += dfs(i,j+1);
    }
    return ans;
}

void solve()
{
    cin >> n >> m;
    for(int i = 0; i < n ;i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
            vis[i][j] = false;
            cin >> a[i][j] ;
        }
    }
    int ans = 0;
    for(int i = 0; i < n ;i ++){
        for(int j = 0; j < m ; j ++){
                if(!vis[i][j] && a[i][j] != 0)
                ans = max(ans , dfs(i,j));
        }
    }
    cout << ans << endl;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t --)
    solve();
    return 0;
}