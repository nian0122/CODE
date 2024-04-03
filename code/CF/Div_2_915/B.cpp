#include<iostream>
#include <vector>

using namespace std;

void solve(){
    int p;
    cin >> p;
    vector<int> map(p + 1, 0);
    int cont = 0;
    int n, m;
    // cout << p << endl;
    for(int i = 0; i < p - 1; i++ ){
        cin >> n >> m;
        // cout << n << ' ' << m << endl;
        map[n]++;
        map[m]++;
        // if(map[n] >= 2 || map[m] >= 2){
        //     cont++;
        // }
    }
    int ans = 0;
    for(int i = 1; i <= p; i++){
        if(map[i] >= 3){
            cont += map[i] - 2;
            // cout << cont << endl;
        }
    }
    ans += cont / 2 + cont % 2;
    cout << ans + 1 << endl;

}

int main(){
    int t ;
    cin >> t ;
    while(t --){
        solve();
    }
}