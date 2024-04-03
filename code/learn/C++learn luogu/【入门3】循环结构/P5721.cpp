#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int main(){
    int n,a=1;
    cin>>n;
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=n-i+1;j++){
            printf("%02d",a);
            a++;
        }
        cout<<endl;
    }
    return 0;
}