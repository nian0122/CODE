#include<iostream>

using namespace std;

const int N=1e3+10;

int n,m,q,x1,y1,x2,y2,c;
int s[N][N],a[N][N];

int main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>s[i][j];
            a[i][j]=s[i][j]-s[i][j-1]-s[i-1][j]+s[i-1][j-1];
        }

    while(q--)
    {
        cin>>x1>>y1>>x2>>y2>>c;
        a[x1][y1]+=c;
        a[x2+1][y1]-=c;
        a[x1][y2+1]-=c;
        a[x2+1][y2+1]+=c;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
            cout<<s[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}