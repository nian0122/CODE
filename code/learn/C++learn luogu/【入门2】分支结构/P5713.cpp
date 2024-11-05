#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n, l, u;
int Local(int n){
    return 5*n;
}
int Luogu(int n){
    return 3*n+11;
}
int main(){
    cin>>n;
    l=Local(n);
    u=Luogu(n);
    cout<<(l > u?"Luogu":"Local");
}