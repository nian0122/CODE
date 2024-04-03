#include<iostream>

using namespace std;
const int N = 1e6 + 10;

int t,n,k,m,h[N],H;

int main(){
    cin >> t;
    while(t --)
    {
        int ans = 0;
        cin >> n >> m >> k >> H;
        for(int i = 0; i < n ;i ++ )
        {
            cin >> h[i];
        }
        for(int i = 0; i < n ; i ++ )
        {
            int hi = abs(H - h[i]);
            if(hi % k == 0 && hi / k < m && hi)ans ++;
            // cout << hi << ' ';
        }
        cout << ans << "\n";
    }

}