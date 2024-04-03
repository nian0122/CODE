#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int p[N];

int main(){
    int t;
    cin >> t;
    while(t --)
    {
        int n,ans = 0;
        cin >> n;
        for(int i = 1;i <= n; i++)
            cin >> p[i];
        
        for(int i = 1;i <= n ; i++)
        {
            int j = i;
            while(i == p[i] && j <=n)
            {
                bool flage = false;
                for(int x = j + 1;x <= n;x ++)
                {   
                    while(x == p[x])
                    {
                        swap(p[i] ,p[x]);
                        ans++;
                        flage = true;
                        break;
                    }
                    if(flage)break;                    
                }
                if(flage)break;
                j ++;
                swap(p[i],p[j]);
                ans ++;
            }
        }
        cout << ans <<endl;
        
    }
}

