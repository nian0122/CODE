#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int sum(int n){
    if(n==1)return 1;
    else return 2*(sum(n-1)+1);
}
int main(){
    int n;
    cin>>n;
    cout<<sum(n);
    return 0;
}