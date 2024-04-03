#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[4];
int main(){
    
    for(int i = 1 ;i<=3;i++)cin>>a[i];
    sort(a+1,a+4);
    for(int i=1;i<=3;i++)
		cout<<a[i]<<" ";
    return 0;
}