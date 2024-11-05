#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int N=1e5+10;

int n;
pair<int ,int> s[N];

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i].first>>s[i].second;
    }
    sort(s,s+n);

    priority_queue<int,vector<int>,greater<int>> heap;
    for(int i=0;i<n;i++){
        if(heap.empty()||heap.top()>=s[i].first)heap.push(s[i].second);
        else {
            heap.pop();
            heap.push(s[i].second);
        }
    }

    cout<<heap.size();
}