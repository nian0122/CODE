#include<bits/stdc++.h>

using namespace std;
struct node {
    int x,y,r;
}; 
int n;
vector<vector<int>> g;
struct p{
    int has,count;
};
p topo_sort() {
    struct p ans;
 int n = g.size();
 int count = 0;
 vector<int> degree(n, 0);
 queue<int> q;
 for (int i = 0; i < n; i++) {
  degree[i] = g[i].size();
  if (degree[i] <= 1) {
   q.push(i);
   count++;
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
    count++;
   }
  }
 }
    ans.count=count;
    ans.has=cnt != n;
 return ans;
}


int main() {
    cin >> n;
    vector<node> ve(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> ve[i].x >> ve[i].y >> ve[i].r;
    }
    g = vector<vector<int>>(n, vector<int>());
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++){
            if(abs(((double)ve[i].x - (double)ve[j].x)*((double)ve[i].x - (double)ve[j].x)+((double)ve[i].y - (double)ve[j].y)*((double)ve[i].y - (double)ve[j].y)) == (ve[i].r + ve[j].r)*(ve[i].r + ve[j].r))
            {
                // cout << i << " " << j << endl;
               g[i].push_back(j);
               g[j].push_back(i);
            } 
        }
    }
    cout << topo_sort().has << endl;

}