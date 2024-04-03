#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> V(3);
int n = 0;
void solve(){
    for(int i = 2; i >= 0; i--){
        cin >> V[i];
    }
    sort(V.begin(),V.end());
    if(V[0] == V[1]){
        cout << V[2] << endl;
    }
    else{
        cout << V[0] << endl;
    }
}

int main(){
    int __;
    cin >> __;
    while(__--){
        solve();
    }
}