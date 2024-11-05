#include <bits/stdc++.h>
using namespace std;
vector<int> fa;
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void unionSet(int i, int j) {
    int x = find(i);
    int y = find(j);
    if(x != y) fa[x] = y;
}

struct edge{
    int u, v, w;
};
bool cmp(edge a, edge b) {
    return a.w < b.w;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<edge> var(m);
    for (int i = 0; i < m; i++) cin >> var[i].u >> var[i].v >> var[i].w;
    //Kruskal
    sort(var.begin(), var.end(), cmp);
    //并查集初始化
    for (int i = 0; i <= n; i++) fa.push_back(i);
    int ans = 0, cont = 0;
    for (int i = 0; i < var.size(); i++) {
        int x = var[i].u;
        int y = var[i].v;
        int w = var[i].w;
        if (find(x) != find(y)) {
            unionSet(x, y);
            ans += w;
            cont++;
        }
        if (cont == n -1) break;
    }
    if (cont == n -1) cout << ans << endl;
    else cout << "orz" << endl;

}