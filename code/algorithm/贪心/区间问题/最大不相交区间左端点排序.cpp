#include<iostream>
#include <cstdio>
#include<algorithm>

using namespace std;

const int N = 1e5+10;

pair<int,int> s[N];
int n,ans=1;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i].first>>s[i].second;
    }
    sort(s,s+n);
    int maxr=0x3f3f3f3f;
    for(int i=0;i<n;i++){
        if(s[i].first<=maxr)maxr=min(maxr,s[i].second);
        else ans++,maxr=s[i].second;
    }
    cout<<ans;
}