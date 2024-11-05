#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int n, k,a=0,b=0;
double j=0,l=0;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        if (i%k==0)
        {
           a += i;
           j++;
        }else{
            b+=i;
            l++;
        }
    }
    cout<<fixed<<setprecision(1)<<a/j<<" "<<b/l;
    return 0;
}