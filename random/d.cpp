#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<int> color;
int last;
bool hasCycle;

bool topo_sort() {
 int n = g.size();
 vector<int> degree(n, 0);
 queue<int> q;
 for (int i = 0; i < n; i++) {
  degree[i] = g[i].size();
  if (degree[i] <= 1) {
   q.push(i);
  }
 }
 int cnt = 0;
 while (!q.empty()) {
  cnt++;
  int root = q.front();
  q.pop();
  for (auto child : g[root]) {
   degree[child]--;
   if (degree[child] == 1) {
    q.push(child);
   }
  }
 }
 return (cnt != n);
}

void dfs(int root) {
 color[root] = 1;
 for (auto child : g[root]) {
  if (color[child] == 1 && child != last) {
   hasCycle = true;
   break;
  }
  else if (color[child] == 0) {
   last = root;
   dfs(child);
  }
 }
 color[root] = 2;
}

int main() {
 int n = 4;
 g = vector<vector<int>>(n, vector<int>());

 g[1].push_back(2);
 g[2].push_back(1);
 g[2].push_back(3);
 g[3].push_back(2);
 g[4].push_back(5);
 g[5].push_back(4);
 cout << topo_sort() << endl; //0，无环
 color = vector<int>(n, 0);
 last = -1;
 hasCycle = false;
 dfs(1);
 cout << hasCycle << endl;  //0，无环

 g[0].push_back(3);
 g[3].push_back(0);
 cout << topo_sort() << endl; //1，有环
 color = vector<int>(n, 0);
 last = -1;
 hasCycle = false;
 dfs(0);
 cout << hasCycle << endl;  //1，有环
 return 0;
}