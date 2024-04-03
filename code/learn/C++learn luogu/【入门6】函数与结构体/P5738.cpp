#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
struct student{
    int a[21];
    double sum;
}stu[101];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>stu[i].a[j];
        }
    }
    for(int i=1;i<=n;i++){
        sort(stu[i].a+1,stu[i].a+m+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=2;j<m;j++){
            stu[i].a[0] += stu[i].a[j];
        }
        stu[i].sum=stu[i].a[0]/double(m-2);
    }
    double p[1001];
    for(int i=1;i<=n;i++)
    p[i]=stu[i].sum;
    sort(p+1,p+n+1);
    cout<<fixed<<setprecision(2)<<p[n];
    return 0;
}