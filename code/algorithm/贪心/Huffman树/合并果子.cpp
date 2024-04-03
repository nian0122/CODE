#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int N=1e4+10;

int n,ans;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> heap;
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        heap.push(j);
    }
    while(heap.size()>1){
        int a=heap.top();
        heap.pop();
        int b=heap.top();
        heap.pop();
        ans+=a+b;
        heap.push(a+b);
    }

    cout<<ans;
}