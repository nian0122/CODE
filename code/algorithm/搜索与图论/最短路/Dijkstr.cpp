/* #include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
struct edge {
  int v, w;
};

struct node {
  double dis;
  int u;

  bool operator>(const node& a) const { return dis > a.dis; }
};

vector<edge> e[maxn];
double dis[maxn];
int vis[maxn];
priority_queue<node, vector<node>, greater<node> > q;

void dijkstra(int n, int s) {
    for (auto &i : dis){
        i = 1e9;
    }
  dis[s] = 100;
  q.push({dis[s], s});
  while (!q.empty()) {
    int u = q.top().u;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] / (1 - w * 0.01)) {
        dis[v] = dis[u] / (1 - w * 0.01);
        q.push({dis[v], v});
      }
    }
  }
}
int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        e[x].push_back({y, z});
        e[y].push_back({x, z});
    }
    int a, b;
    cin >> a >> b;
    dijkstra(n, b);
    printf("%0.8lf",dis[a]);
} */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> ver(n + 1, vector<int>());
    vector<vector<int>> edge(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        ver[x].push_back(y);
        ver[y].push_back(x);
        edge[x].push_back(z);
        edge[y].push_back(z);
    }
    int a, b;
    cin >> a >> b;
    vector<double> dist(n + 1, 1e9);
    vector<int> expand(n + 1, false);
    dist[b] = 100;
    priority_queue<pair<double,int>> q;
    q.push(make_pair(-dist[b], b));
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        if (expand[x]) continue;
        expand[x] = true;
        for (int i =0; i < ver[x].size(); i++ ) {
            int y = ver[x][i];
            int z = edge[x][i];
            if (dist[x] / (1 - z * 0.01) < dist[y]) {
                dist[y] = dist[x] / (1 - z * 0.01);
                q.push(make_pair(-dist[y],y));
            }

        }
    }
    printf("%0.8lf",dist[a]);
}