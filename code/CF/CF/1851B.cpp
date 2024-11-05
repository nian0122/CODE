#include <iostream>
#include<algorithm>

using namespace std;
const int N = 2e5 + 10;

int q[N],even[N],odd[N],e[N],o[N],p[N];

int juge(int i)
{
    return i & 1;
}

int main(){
    int t;
    cin >> t;
    while(t -- )
    {
        int n;
        int tt=0,hh=0;
        cin >> n;
        for(int i = 0;i < n;i++)
        {
            cin >> q[i];
            if(juge(q[i]))
            {
                even[tt] = i;
                e[tt] = q[i]; 
                tt++;
            }
            else 
            {
                odd[hh] = i;
                o[hh] = q[i];
                hh ++;
            }
        } 
        sort(o,o + hh);
        sort(e,e + tt);
        
        for(int i = 0;i < tt;i ++)
        {
            p[even[i]]=e[i];
        }
        for(int i = 0;i < hh;i ++)
        {
            p[odd[i]]=o[i];
        }
        
        bool flage = false;
        for(int i = 0;i < n-1;i++ )
        {
            if(p[i] > p[i+1])flage = true;
        } 
        if(!flage)cout << "YES"<<"\n";
        else cout <<"NO"<<"\n";
    }
}