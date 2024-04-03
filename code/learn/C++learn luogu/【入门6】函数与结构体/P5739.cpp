#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int n;
int a(int n){
    if(n==1)return 1;
    else return n*a(n-1);
}
int main(){
    cin>>n;
    cout<<a(n);
    return 0;
}