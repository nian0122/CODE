#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int> > tims(m , vector<int>(3, 0));
    for (int i = 0; i < m; i++) {
        cin >> tims[i][0] >> tims[i][1] >> tims[i][2];
    }
    int a, b;
    cin >> a >> b;
    vector<double> dist(n + 1, INT64_MAX);
    dist[b] = 100;
    for (int i = 0; i < n - 1; i++) {
        bool flag = false;
        for(auto edge : tims) {
            int x = edge[1];
            int y = edge[0];
            int z = edge[2];
            if (dist[x] / (1 - z * 0.01) < dist[y]) {
                dist[y] = dist[x] / (1 - z * 0.01);
                flag = true;
            }
        }
        if (!flag) break;
    }
    printf("%0.8lf",dist[a]);
    return 0;
}