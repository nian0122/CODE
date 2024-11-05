#include<iostream>
#include<vector>

using namespace std;
#define int long long

void solve()
{
    int l = 1,r = 1e9;
    int n , c;
    cin >> n >> c;
    vector<int> a(n);
    for(int i = 0; i < n ; i++ )cin >> a[i];
    while(l <= r)
    {
        int mid = l + ( r - l + 1 )/2;
        int sumall = 0;
        for(int i = 0; i < n ;i ++)
        {
            sumall += (a[i] + 2 * mid) * (a[i] + 2 * mid);
            if (sumall > c)break;
        }
        if( sumall == c)
        {
            cout << mid << '\n';
            return;
        }
        if(sumall > c)
        {
            r = mid - 1;
        }
        else 
        {
            l = mid + 1;
        }
        
    }   
    
}

int32_t main(){
    int t ;
    cin >> t;
    while (t --)
    {
        solve();
    }
}