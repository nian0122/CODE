#include<iostream>

using namespace std;

const int N=1e5+10;

int a[N],q[N],tt=-1,hh=0;
int n,k;

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];

    tt=-1,hh=0;
    for(int i=0;i<n;i++){
        if(hh<=tt&&q[hh]<i-k+1)hh++;
        while(hh<=tt&&a[q[tt]]>=a[i])tt--;
        q[++tt]=i;
        if(i>=k-1)cout<<a[q[hh]]<<" ";
    }
    cout<<endl;

    tt=-1,hh=0;
    for(int i=0;i<n;i++){
        if(hh<=tt&&q[hh]<i-k+1)hh++;
        while(hh<=tt&&a[q[tt]]<=a[i])tt--;
        q[++tt]=i;
        if(i>=k-1)cout<<a[q[hh]]<<" ";
    }
}