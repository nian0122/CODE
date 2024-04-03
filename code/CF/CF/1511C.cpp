//1511C
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<vector>
#include<numeric>
#define endl '\n'
// #define int long long
#define all(a) (a).begin(),(a).end()
#define sz(a) (a).size()
using namespace std;
const int N = 1e5 + 10;


int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    scanf("%d%d", &n, &q);
    vector<int> a(n);
    for (int& x : a) scanf("%d", &x);
    while (q--) {
    int x;
    scanf("%d", &x);
    int p = find(a.begin(), a.end(), x) - a.begin();
    printf("%d ", p + 1);
    rotate(a.begin(), a.begin() + p, a.begin() + p + 1);
  }
    return 0;
}