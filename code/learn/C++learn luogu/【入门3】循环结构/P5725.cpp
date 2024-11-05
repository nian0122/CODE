#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int n;
int main(){
    cin>>n;
    int a=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%02d",a);
            a++;
        }
    cout<<endl;
    }
    cout<<endl;
    a=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            printf("  ");
        }
        for(int j=1;j<=i;j++){
            printf("%02d",a);
            a++;
        }
        cout<<endl;
    }
    return 0;
}
