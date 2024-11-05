#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int m, t, s, a, b;
int main(){
    cin>>m>>t>>s;
    if(t==0)cout<<0;
    else{
    if(s%t==0)b = s / t;
    else b = s / t + 1;
    if(b<=m)cout<<m-b;
    else cout<<0;}
    return 0;
}