#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int n, a[200];
int main(){
    cin>>n;
    int i=1;
    while(n>1){
        a[i]=n;
        if(n%2==0) n/=2;
        else n=n*3+1;
        i++;
    }
    a[i]=1;
    for(int j=i;j>=1;j--)cout<<a[j]<<" ";
    return 0;
}