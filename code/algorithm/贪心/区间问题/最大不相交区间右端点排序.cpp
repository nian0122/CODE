#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5+10;

int en=-0x3f3f3f3f;
int ans,n;

struct Range {
    int r,l;
    bool operator< (const Range &w)const{
        return r<w.r;
    }
}range[N];

int main(){
    
    cin>>n;
    for(int i=0;i< n;i++){
        cin>>range[i].l>>range[i].r;
    }
    sort(range,range+n);
    for(int i=0;i<n;i++){
        if(range[i].l>en){
            ans++;
            en=range[i].r;
        }
    }
    cout<<ans<<endl;
}