#include<algorithm>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;
int p[4];
//欧几里得算法（辗转相除法）求公因数
int gcd(int a,int b){
    return b ? gcd(b, a % b) : a;
    // if(b==0)return a;
    // return gcd(b,a%b);
}
int main(){
    cin>>p[1]>>p[2]>>p[3];
    sort(p+1,p+4);
    cout<<p[1]/gcd(p[1], p[3])<<"/"<<p[3]/gcd(p[1], p[3]);
    return 0;
}