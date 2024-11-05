#include<iostream>
#include<cstdio>
#include<cmath>
#define P 3.14;
using namespace std;
double h, r, v, t;
int main(){
    cin>>h>>r;
    v =r * r * h * P;
    t = ceil(20000 / v);
    cout<<t<<endl;
    return 0;

}