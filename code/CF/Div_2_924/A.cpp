#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(){
    vector<int> ve(2);
    vector<int> index(3);
    for(int i = 0; i < 2; i++) {
        cin >> ve[i];
    }
    sort(ve.begin(), ve.end());
    if ((ve[0] & 1) && (ve[1] & 1)){
        cout << "No" << endl;
    }else {
        puts(((ve[0] & 1) && ve[0] * 2 == ve[1]) ? "No" : "Yes");
    }
    
}
int main(){
    int __;
    cin >> __;
    while(__--){
        solve();
    }
}