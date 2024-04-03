#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
using namespace std;
const int N = 1e5 + 10;
int a[N];
void solve()
{
    int n,x;
    cin >> n >> x;
    int s = 0;
    for(int  i = 0 ;i < 3 ;i ++)
    {
        for(int j = 0 ; j < n ; j ++ )cin >> a[j];
        for(int j = 0 ; j < n ; j ++ ){
            if((x | a[j]) != x) break;
            s |= a[j] ;
        }
    }
    if (s == x) cout << "YES\n";
    else cout << "NO\n";
    
}

int main(){
    int t;
    cin >> t;
    while(t --)
    solve();
    return 0;
}