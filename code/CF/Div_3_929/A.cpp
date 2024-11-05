#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

void solve() { 
    int n;
    cin >> n;
    vector<int> ve(n);
    for(int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    sort(ve.begin(), ve.end());
    // for(int i = 0; i < n; i++) {
    //     cout << ';'<< ve[i] << endl;
    // }
    
    
    if(ve[0] >= 0) {
        int t = 0;
        t = accumulate(ve.begin(), ve.end(), 0);
        cout << t << endl;
    }
    else {
        bool flage = false;
        for(int j = 0; j < n; j ++) {
            if (ve[j] <= 0){
                continue;
            }else{
                flage = true;
                int t = 0;
                t = accumulate(ve.begin(), ve.begin() + j, 0);
                int z = 0;
                z = accumulate(ve.begin()+j, ve.end(), 0);
                cout << -t + z << endl;
                break;
            }
            
        }
        if(!flage){
            int t = 0;
            t = accumulate(ve.begin(), ve.end(), 0);
            cout <<-t << endl;                
        }
    }
}
    



int main() {
    int __;
    cin >> __;
    while(__--){
        solve();
    }
}