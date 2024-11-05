#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<vector>
#define endl '\n'
#define int long long
#define all(a) (a).begin(),(a).end()
using namespace std;

void solve()
{
    int n , k ;
    cin >> n >> k ;
    string s;
    cin >> s;
    string odd, even;
    for(int i = 0 ; i < n ; i ++){
        if( i & 1) odd.push_back(s[i]);
        else even.push_back(s[i]);
    }
    sort(all(odd));sort(all(even));
    string ans;
    for(int i = 0,j = 0; i < odd.size() || j < even.size() ; i ++ , j ++){
        if (j < even.size() ) ans.push_back(even[j]);
        if(i < odd.size()) ans.push_back(odd[i]);
    }
    if(k & 1) cout << ans <<endl;
    else {
        sort(all(s));
        cout << s << endl;
    }
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t --)
    solve();
    return 0;
}