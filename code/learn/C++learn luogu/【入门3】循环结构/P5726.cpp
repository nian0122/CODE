#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int n,ans;
int a[1004];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<n-1;i++)ans+=a[i];
    printf("%.2lf",ans/(double)(n-2));
    return 0;
}