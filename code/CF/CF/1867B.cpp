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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t(n + 1 ,'0');
    int tmp_1 = 0,tmp_2 = 0, ans = 0;
    for (int i = 0; i <= n / 2 - 1 ; i ++){
        if(s[i] == s[n - i - 1])
            tmp_1 ++;
        else
            ans ++;
    }
    if(n & 1) tmp_2++;
    for(int j = 0;j <= tmp_1;++j)
        {
            for(int k = 0;k <= tmp_2;++k)
            {
                t[ans + j*2 + k] = '1';
            }
        }
        cout << t << "\n";
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t --)
    solve();
    return 0;
}