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
      // ע���������ý�ѭ��������������һά����һ��ֱ�� while (x <= n) ��
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
  // ��ѯ�Ӿ����
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
