#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int w, x, h,q,ans=0, p[105][7], m[21][21][21];
int main(){
    cin>>w>>x>>h;
    cin>>q;
    for(int i=1;i<=q;i++)cin>>p[i][1]>>p[i][2]>>p[i][3]>>p[i][4]>>p[i][5]>>p[i][6];
    for(int dex=1;dex<=q;dex++)
    {
        for(int i=min(p[dex][1],p[dex][4]); i<=max(p[dex][1],p[dex][4]); i++)
        {
            for(int j=min(p[dex][2],p[dex][5]); j<=max(p[dex][2],p[dex][5]); j++)
            {
                for(int k=min(p[dex][3],p[dex][6]); k<=max(p[dex][3],p[dex][6]); k++)
                {
                        m[i][j][k]=1;
                }
            }
        }
    }
    for(int i=1; i<=w; i++)
    {
        for(int j=1; j<=x; j++)
        {
            for(int k=1; k<=h; k++)
            {
                if(m[i][j][k]==0)
                {
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}