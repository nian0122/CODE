#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#define endl '\n'
#define int long long
using namespace std;

int min_divisor(int n)
{
    for(int i = 2; i < sqrt(n) + 1;i ++)
    {
        if (n % i == 0)
        {
            return i;
            break;
        }
    }
    return n;
}

void solve()
{
    int l,r;
    cin >> l >> r;
    bool flage = true;
    for(int i = l;i <= r;i ++)
    {
        int min = min_divisor(i);
        if ( min != i)
        {
            cout << min << ' ' << i - min << endl;
            flage = false;
            break;
        }
        
    }
    if(flage)cout << -1 << endl;
    

}

int32_t main(){
    int t;
    cin >> t;
    while(t --)
    solve();
    return 0;
}