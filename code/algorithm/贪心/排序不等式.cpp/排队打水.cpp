#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
const int N=1e5+10;

ll sum;
int n;
vector<int> a;
int main(){
    cin>>n;
    while(n--){
        int i;
        cin>>i;
        a.push_back(i);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    for(int i=0;i<a.size();i++){
        sum += a[i]*i;
    }
    cout<<sum;

}