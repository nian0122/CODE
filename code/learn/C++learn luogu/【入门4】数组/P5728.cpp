#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int a[1001][5],n,p=0,sum[1010];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        sum[i] = a[i][1]+a[i][2]+a[i][3];
    }
    for (int i = 1; i <= n; i++) 
        for (int j = i+1; j <= n; j++){
            if((abs(a[i][1]-a[j][1])<=5)&&
                (abs(a[i][2]-a[j][2])<=5)&&
                (abs(a[i][3]-a[j][3])<=5)&&
                (abs(sum[i] - sum[j])<=10))
                p=p+1;
        }
    cout<<p<<endl;      
    return 0;
}