#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

int count = 0;

void solve() {
    int n;
    cin >> n;
    vector<int> ve(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    int sum = accumulate(ve.begin(), ve.end(), 0);
    if (sum % 3 == 0){
        cout << 0 << endl;
    }else if (sum % 3 == 2) {
        cout << 1 << endl;
    }else {
        bool flage = false;
        for (int i = 1; i <= n; i++) {
            int T = sum - ve[i];
            if(T % 3 == 0) {
                flage = true;
                cout << 1 << endl;
                break;
            }
        }
        if(!flage) {
            cout << 2 << endl;
        }
    }
    // cout << count++ << ";;"<< endl;
}

int main() {
    int __;
    cin >> __;
    while(__--) {
        solve();
    }
}