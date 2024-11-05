#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double a,b;
int main(){
    cin>>a;
    if(a<=150){
        b = a*0.4463;
    }else if(a>=151&&a<=400){
        b += 150*0.4463;
        b += (a-150)*0.4663;
    }else{
        b += 150*0.4463;
        b += (400-150)*0.4663;
        b += (a-400)*0.5663;
    }
    cout<<fixed << setprecision(1) << b;
}