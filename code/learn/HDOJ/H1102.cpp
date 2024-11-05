#include <iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,num;
int dis[105][105];

class village
{
public:
    int u,v,w;

};
village vil[10000];
int node[105];
int cmp(const village &p,const village &q)
{
    return p.w<q.w;
}
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        node[i]=i;

    }

}
int finds(int x)
{
    if(x==node[x])
        return x;
    return finds(node[x]);
}
void unite(int x,int y)
{
    x=finds(x);
    y=finds(y);
    if(x==y)
        return;
    node[x]=y;
}
int kru()
{
    sort(vil,vil+num,cmp);
    int an=0;
    for(int i=0;i<num;i++)
    {
        if(finds(vil[i].u)!=finds(vil[i].v))
        {
            an+=vil[i].w;
            unite(vil[i].u,vil[i].v);
        }
    }
    return an;
}
int main()
{
    int i,j;
   while(scanf("%d",&n)!=EOF)
   {
       num=0;
       for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
        cin>>dis[i][j];
    }
    for(i=1;i<=n;i++)
        for(j=1;j<i;j++)
    {
        vil[num].u=i;
        vil[num].v=j;
        vil[num++].w=dis[i][j];

    }
    init(n);
    int q;
    scanf("%d",&q);
    while(q--)
    {
       int a,b;
       scanf("%d%d",&a,&b);
       unite(a,b);
    }

    cout<<kru()<<endl;
   }
}