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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n;i ++){
        cin >> a[i];
    }
    if(a[1] != n)cout << "NO" << endl;
    else {
        vector<int> b;
        for(int i = n; i >= 1 ; i --){
            while(b.size() < a[i]){
                b.push_back(i);
            }
        }
        bool flage = true;
        for(int i = 1 ; i <= n;i ++){
            if( a[i] != b[i - 1]){
                cout << "NO" << endl;\
                flage = false;
                break;
            }
        }
        if(flage)cout << "YES" << endl;
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