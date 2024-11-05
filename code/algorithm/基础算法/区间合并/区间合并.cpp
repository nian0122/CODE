#include<iostream>
#include<algorithm>
 
using namespace std;

const int N=1e6+10;

struct pai{
    int first,second;
}a[N];

//结构体排序
bool cmp( pai& x,pai& y)
{
    if(x.first!=y.first)return x.first<y.first;
    else return x.second<y.second;
}
    

int main()
{   //录入
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;

    //排序
    sort(a+1,a+n+1,cmp);
    
    //区间合并
    int ed=a[1].second,ans=0;
    for(int i=2;i<=n;i++)
    {
        if(ed>=a[i].first)ed=max(ed,a[i].second);
        else ans++,ed=a[i].second;
    }
    cout<<ans+1<<endl;

}