#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cstring>
using namespace std;
string a;
int main(){
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]<='z'&&a[i]>='a')a[i]=a[i]+('A'-'a');
    }
    cout<<a;
    return 0;
}