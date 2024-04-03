#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
using namespace std;
const int N = 2e5 + 10;
long long a[N];
int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n,x;
        cin >> n >> x;
        for(int i = 1;i <= n; i ++)
        {
            cin >> a[i];
        }
        long long l =0,r=2000000007;
        while(l < r)
        {
            long long tot = 0;
            long mid = l + (r - l + 1) / 2;
            for (int i = 1; i <= n;i ++)
            {
                tot += max(mid - a[i],0LL); 
            }
            
            if (tot <= x) l = mid;
            else r = mid - 1;  
        }
        cout << r << endl;

    }
    return 0;
}