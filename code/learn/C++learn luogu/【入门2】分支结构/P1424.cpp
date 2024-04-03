#include<iostream>
using namespace std;
int a=0, x, n;
long long ans;
int main(){
    cin>>x>>n;
    for(int i=1;i<=n;i++){        
        if((x+1)%7==0||x%7==0){
            x++;
        }
        else {x++;a++;}
        
    }
    ans=a*250;
    cout<<ans;
    return 0;
}