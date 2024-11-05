#include<iostream>

using namespace std;

const int N=1e6+10;

int n,m,l,r,c;
int a[N],b[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i]-a[i-1];
    }

    while(m--)
    {
        cin>>l>>r>>c;
        b[l]+=c;
        b[r+1]-=c;
    }

    for(int i=1;i<=n;i++)a[i]=a[i-1]+b[i];
    for(int i=1;i<=n;i++)cout<<a[i];

    return 0;
}