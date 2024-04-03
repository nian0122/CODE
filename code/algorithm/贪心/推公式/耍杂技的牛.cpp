#include<iostream>
#include<algorithm>

using namespace std;

const int N=5e5+10;

int n;
pair<int,int> cow[N];

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int w,s;
        cin>>w>>s;
        cow[i]={w+s,w};
    }
    sort(cow,cow+n);

    int res = -2e9, sum = 0;
    for (int i = 0; i < n; i ++ )
    {
        int s = cow[i].first - cow[i].second, w = cow[i].second;
        res = max(res, sum - s);
        sum += w;
    }
    cout<<res;
}
