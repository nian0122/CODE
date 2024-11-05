#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int x,y,b=0,j[10000000];
bool a(int n){
    return ((n%4==0&&n%100!=0)||(n%400==0))?1:0;
}
int main(){
    cin>>x>>y;
    for(int i=x;i<=y;i++){
        if(a(i)){
            b++;
            j[b]=i;
        }
    }
    cout<<b<<endl;
    for(int i=1;i<=b;i++)cout<<j[i]<<" ";
    return 0;
}