#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int n;
struct student{
    int p;
    int a,b;
    int sum;
    int c;
}stu[1001];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>stu[i].p>>stu[i].a>>stu[i].b;
        stu[i].sum=stu[i].a+stu[i].b;
        stu[i].c=stu[i].a*7+stu[i].b*3;
    }
    for(int i=1;i<=n;i++){
        if(stu[i].sum>140&&stu[i].c>=800)cout<<"Excellent"<<endl;
        else cout<<"Not excellent"<<endl;
    }
    return 0;
}