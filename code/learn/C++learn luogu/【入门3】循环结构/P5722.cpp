#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int main(){
    int n,ans;
    cin>>n;
    for(int i=1;i<=n;i++)ans+=i;
    cout<<ans;
    return 0;
}