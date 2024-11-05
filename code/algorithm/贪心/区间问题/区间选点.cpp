#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

vector<pair<int,int>> a;
int cnt;


int main(){
    int n;
    cin>>n;
    while(n--){
        int l,r;
        cin>>l>>r;
        a.push_back({r,l});
    }
    sort(a.begin(),a.end());

    int ed=-0x3f3f3f3f;
    for(int i=0;i < a.size();i++){
        if(a[i].second > ed){
            cnt++;
            ed = a[i].first;
        }
    }
    cout<<cnt;

}