#include<bits/stdc++.h>
using namespace std;
const int N = 210;
int n, a, b, ans = 0;
vector<int> ve(N);
int flage[N];
void dfs(int a, int b, int ans){
    if(a == b){
        cout << ans;
        return;
    }
    //    cout << flage[5] << " " << 5 << endl;
    if(a - ve[a] > 0 && !flage[a - ve[a]]){
        
        // cout << flage[a - ve[a]] << " " << a - ve[a] << endl;
        flage[a - ve[a]] = 1;
        return dfs(a - ve[a], b, ans+1);
    }
    if(a + ve[a] <= n && !flage[a + ve[a]]){
        
        // cout << flage[a + ve[a]] << " " << a + ve[a] <<endl;
        flage[a + ve[a]] = 1;
        return dfs(a + ve[a], b, ans+1);
    }
}
int main(){
    cin  >> n >> a >> b;
    for(int i = 1; i <= n; i++){
        flage[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> ve[i];
    }
    dfs(a,b,ans);
}