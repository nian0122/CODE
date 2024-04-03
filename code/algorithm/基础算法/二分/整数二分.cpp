#include<iostream>

using namespace std;

int n,m,l,r,mid;
int q[100010];

int bsearch_1(int q[] ,int k,int n)//较大值
{
    int l=0,r=n-1;
    while(l<r)
    {
        mid=(r+l+1)>>1;
        if(q[mid]<=k)l=mid;
        else r=mid-1;
    }  
    return l;  
}

int bsearch_2(int q[],int k,int n)//较小值
{
    int l=0;r=n-1;
    while(l<r)
    {   
        mid=(r+l)>>1;
        if(q[mid]>=k)r=mid;
        else l=mid+1;
    }
    return l;
}

int main()
{
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++)scanf("%d",&q[i]);

    while(m--)
    {
        int k;
        scanf("%d",&k);

        l=bsearch_2(q,k,n);
        
        if(q[l] != k)cout<<"-1 -1"<<endl;
        else
        {
            cout<<l<<" ";
            
            l=bsearch_1(q,k,n);
           
            cout<<l<<endl;
        }
        
    }

    return 0;
}