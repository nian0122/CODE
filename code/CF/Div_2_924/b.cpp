#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> ve(n);
    for(int& i : ve){
        cin >> i;
    }
    //排序去重
    sort(ve.begin(),ve.end());
    ve.erase(unique(ve.begin(), ve.end()), ve.end());
    // for(auto i : ve){
    //     cout << i << endl;
    // }
    // cout << ve.size() << n << endl;
    int ans = 0;
    for(int l = 0, r = 0; l < ve.size(); l++) {
        while(r < ve.size() && ve[l] + n - 1 >= ve[r]) r++;
        ans = max(ans, r - l);
    }
    cout << ans << endl;
    
}

int main() {
    int __;
    cin >> __;
    while (__--)
    {
        solve();
    }
    
}