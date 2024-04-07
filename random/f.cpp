#include<bits/stdc++.h>
using namespace std;
const int N = 210;
int n, a, b, ans = INT32_MAX;
int ve[N];
int flage[N];
void dfs(int a, int step){
    // cout << a << "      " < step << "     " << flage[a] << "     " << b << endl;
    if(a < 1 || a > n || step >= flage[a]){
        return;
    }
    if(a == b){
        // ans =min(ans, step);
        ans = step;
        return;
    }
    flage[a] = step;
    dfs(a - ve[a], step+1);
    dfs(a + ve[a], step+1);
    // flage[a] = 0;
    return;
}
int main(){
    cin  >> n >> a >> b;
    for(int i = 1; i <= n; i++){
        flage[i] = INT32_MAX;
    }
    for(int i = 1; i <= n; i++){
        cin >> ve[i];
    }
    dfs(a,0);
    // cout << ans;
    cout << (ans == INT32_MAX ? -1 : ans);
}