#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int n;
int a[100];
bool prime(int x){
    if(x<=1)return false;
    for(int i =2;i<=sqrt(x);i++){
        if(x%i==0)
        return false;
    }
    return true;
}
int main(){
    cin>>n;
    int m;
    while(n--){
        cin>>m;
        if(prime(m))cout<<m<<" ";
    }
    return 0;
}