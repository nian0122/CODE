#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int s,ans=2100000000;
int n;
struct pen
{
    double a;
    int b;
}p[4];
int main(){
    cin>>n;
    for(int i=1;i<=3;i++)cin>>p[i].a>>p[i].b;
    for(int i=1;i<=3;i++){
        s =ceil(n/p[i].a)*p[i].b;
        if(s<ans)ans=s;
    }
    cout<<ans;
    return 0;
}