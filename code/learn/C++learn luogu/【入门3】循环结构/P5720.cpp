#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int main(){
    int a,day=1;
    cin>>a;
    while(a>1){
        day++;
        a /= 2;
    }
    cout<<day;
    return 0;
}