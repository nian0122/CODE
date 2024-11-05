#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e5+10;

int s,t;
pair<int, int> range[N];
int n,ans;
bool flage=false;

int main(){
    cin>>s>>t;
    cin>>n;
    for (int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        range[i]={l,r};
    }
    sort(range,range+n);

    for(int i=0;i<n;i++){
        int j=i,r=-0x3f3f3f3f;
        while(j<n&&range[j].first<=s){
            r=max(r,range[j].second);
            j++;
        }
        ans++;
        if(r<s){
            ans=-1;
            break;
        }
        if(r>=t){
            flage=true;
            break;
        }
        s=r;
        i=j-1;

    }
    if(!flage)cout<<"-1";
    else cout<<ans;
}