#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>//���� deque˫�˶��� priority_queue����� priority_queue<int,vector<int>,greater<int>>С����
#include<list>
#include<vector>
#include<numeric>
#include<stack>//ջ
#define endl '\n'
// #define int long long
#define all(a) (a).begin(),(a).end()
#define sz(a) (a).size()
using namespace std;
const int N = 1e5 + 10;

void solve()
{
    int n , k , x;
    cin >> n >> k >> x;
    if( min(n, x + 1) < k){
        cout << -1 << endl;
    }
    else if(k == x){
        
        int sum = ( k - 1) * k / 2 + (n - k)*(k - 1);
        cout << sum << endl;
    }
    else{
        int sum = ( k - 1) * k / 2 + (n - k)*x;
        cout << sum << endl;
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
// for (int& x : a) scanf("%d", &x);
//for(scanf("%d",&x);x;scanf("%d",&x))