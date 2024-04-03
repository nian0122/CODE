#include<iostream>

using namespace std;
const int N = 1e3 + 10;
int a[N][N] , c[N][N];
int n,m,q;

int lowbit(int x){
    return x & -x;
}

void add(int x, int y, int v) {
  for (int i = x; i <= n; i += lowbit(i)) {
    for (int j = y; j <= m; j += lowbit(j)) {
      // 注意这里必须得建循环变量，不能像一维数组一样直接 while (x <= n) 了
      c[i][j] += v;
    }
  }
}
int sum(int x, int y) {
  int res = 0;
  for (int i = x; i > 0; i -= lowbit(i)) {
    for (int j = y; j > 0; j -= lowbit(j)) {
      res += c[i][j];
    }
  }
  return res;
}

int ask(int x1, int y1, int x2, int y2) {
  // 查询子矩阵和
  return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
}

int main(){
    cin >> n >> m;
    int op;

    while (cin >> op) {
        if (op == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            add(x, y, k);
        } else {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            cout << ask(a, b, c, d) << '\n';
        }
    }
}
