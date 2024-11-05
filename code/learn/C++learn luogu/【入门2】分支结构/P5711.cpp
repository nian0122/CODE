#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
bool a;
int main(){
    cin>>n;
    cout<<((n%4==0&&n%100!=0)||(n%400==0))?1:0;
    // if(n % 100 == 0)
    // {
    //     a = n % 400;
    //     cout<<!a;
    // }
    // else{
    //     a = n % 4; 
    //     cout<<!a;
    // }
    // return 0;
}