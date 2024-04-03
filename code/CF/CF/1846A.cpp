#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t,n;

int main(){
    cin >> t;
    while(t --)
    {
        cin >> n;
        vector<pair<int ,int>> nail(n + 1);
        for(int i = 1;i <= n;i ++ )
        {
            int a,b;
            cin >> a >> b;
            nail[i] = {a,b};
        }
        // for(int i = 1;i <= n;i ++)
        // {
        //     cout << nail[i].first << " " << nail[i].second <<endl;
        // }
        int ans = 0;
        for(int i =1;i <= n ; i ++ )
        {
            if(nail[i].first > nail[i].second)
            {
                ans ++;
            }
        }
        cout << ans << "\n";
    }
}