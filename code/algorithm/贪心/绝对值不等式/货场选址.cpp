#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e6+10;

int n,sum;
int a[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n);
    for(int i=0;i<n;i++){
        sum +=abs(a[i]-a[n>>1]);
    }
    cout<<sum;
}
