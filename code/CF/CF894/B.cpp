#include<cmath>
#include<iostream>
// #include<algorithm>
// #include<cstdio>
// #include<iomanip>
// #include<queue>//队列 deque双端队列 priority_queue大根堆 priority_queue<int,vector<int>,greater<int>>小根堆
// #include<list>
#include<vector>
// #include<numeric>
// #include<stack>//栈
// #define endl '\n'
// #define int long long
// #define all(a) (a).begin(),(a).end()
// #define sz(a) (a).size()
using namespace std;
const int N = 1e5 + 10;

void solve()
{
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (i && a.back() > x) {
                a.push_back(1);
            }
            a.push_back(x);
        }
        cout << a.size() << "\n";
        for (int el : a)
            cout << el << " ";
        cout << "\n";
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