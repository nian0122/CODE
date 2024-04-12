#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 60;
int a[N][N], s[N][N];
int ans = 0;

signed main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = 0;
            a[i][j] = 0;
        }
    }
    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[x2 + 1][y2 + 1] +=1;
        a[x1][y1] += 1;
        a[x2 + 1][y1] -= 1;
        a[x1][y2 + 1] -= 1;
    }
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]; 
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
}