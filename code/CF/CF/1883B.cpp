#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>//队列 deque双端队列 priority_queue大根堆 priority_queue<int,vector<int>,greater<int>>小根堆
#include<list>
#include<vector>
#include<numeric>
#include<stack>//栈
#include<map>
#define endl '\n'
// #define int long long
#define all(a) (a).begin(),(a).end()
#define sz(a) (a).size()
using namespace std;
const int N = 1e5 + 10;
//回文字特性 检查出现奇数次的字母（记为x）的数量不大于 x+1
void solve(){
    string s;
    int n,k;
    map<char ,int> a;
    cin >> n >> k >> s;
    for(int i = 0 ; i < n ; i++){
        if(a.find(s[i]) != a.end()){
            a[s[i]] += 1; 
        }
        else a[s[i]] = 1;
    }
    int odd = 0,even = 0;
    for(auto it = a.begin() ; it != a.end() ; it ++){
        if(it->second & 1){
            odd += 1;
        }
        else even += 1;

    }

    odd -= k;
    if(odd > 1 ){
        cout << "NO"<<endl;
    }
    else cout << "YES" <<endl;
    

    

}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t --)
    solve();
    return 0;
}