#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int n,a[10][10];
int main(){
    a[1][1]=1;
    cin>>n;    
    for(int x=1,y=1,i=1;i<n*n;){
        while(++y<=n&&!a[x][y])a[x][y]=++i;--y;
        while(++x<=n&&!a[x][y])a[x][y]=++i;--x;
        while(--y> 0&&!a[x][y])a[x][y]=++i;++y;
        while(--x> 0&&!a[x][y])a[x][y]=++i;++x;
    }
    for(int i=1;i<=n;++i,cout<<endl)for(int j=1;j<=n;++j)
    cout<<setw(3)<<a[i][j];
    return 0;
}
