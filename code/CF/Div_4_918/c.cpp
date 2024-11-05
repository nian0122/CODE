#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<numeric>
#include<cmath>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> ve(n);
    long long T = 0;
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
        T += ve[i];
    }
    if (sqrt(T) == (int)sqrt(T)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}

int main(){
    int __;
    cin >> __;
    while(__--){
        solve();
    }
}