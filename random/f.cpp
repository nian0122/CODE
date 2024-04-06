#include<bits/stdc++.h>
using namespace std;
const int N = 210;
int n, a, b, ans = INT32_MAX;
vector<int> ve(N);
int flage[N];
void dfs(int a, int b, int sum){
    if(a < 1 || a > n || flage[a]){
        return;
    }
    if(a == b){
        ans = sum;
        return;
    }
    return dfs(a - ve[a], b, sum+1);
    return dfs(a + ve[a], b, sum+1);
}
int main(){
    cin  >> n >> a >> b;
    for(int i = 1; i <= n; i++){
        flage[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> ve[i];
    }
    dfs(a,b,0);
    if(ans == INT32_MAX){
        cout << -1;
    }else{
        cout << ans;
    }
}