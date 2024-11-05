#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int n, k[2000004],y;
double x;
int main(){
    cin>>n;
    while(n--){
        cin>>x>>y;
        for(int i=1;i<=y;i++){
            if(k[int(x*i)]==0)k[int(x*i)]=1;  
            else k[int(x*i)]=0;
        }      
    }
    for(int i=1;;i++){
        if(k[i]==1){
            cout<<i;
            break;
        }
    }
    return 0;
}