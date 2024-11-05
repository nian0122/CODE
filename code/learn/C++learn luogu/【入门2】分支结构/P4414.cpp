#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int p[4],ch;
char a[4];
int main(){
    cin>>p[1]>>p[2]>>p[3];
    sort(p+1,p+4);
    cin>>a[1]>>a[2]>>a[3];
    for(int i;i<=3;i++){
        if(a[i]=='A'){ch=1;cout<<p[ch]<<" ";}
        else if (a[i]=='B'){ch=2;cout<<p[ch]<<" ";}
        else if (a[i]=='C'){ch=3;cout<<p[ch]<<" ";}
    }
    return 0;
}