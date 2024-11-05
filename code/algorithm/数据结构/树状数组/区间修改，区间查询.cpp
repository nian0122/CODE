#include<iostream>
#define int long long

using namespace std;
const int MAXN = 1e6 + 10;

int t1[MAXN], t2[MAXN], n , q;

int lowbit(int x) { return x & (-x); }

void add(int k, int v) {
  int v1 = k * v;
  while (k <= n) {
    t1[k] += v, t2[k] += v1;
    // 注意不能写成 t2[k] += k * v，因为 k 的值已经不是原数组的下标了
    k += lowbit(k);
  }
}

int getsum(int *t, int k) {
  int ret = 0;
  while (k) {
    ret += t[k];
    k -= lowbit(k);
  }
  return ret;
}

void add1(int l, int r, int v) {
  add(l, v), add(r + 1, -v);  // 将区间加差分为两个前缀加
}

long long getsum1(int l, int r) {
  return (r + 1ll) * getsum(t1, r) - 1ll * l * getsum(t1, l - 1) -
         (getsum(t2, r) - getsum(t2, l - 1));
}


int32_t main(){ 
    cin >> n >> q;
    for(int  i = 1 ; i <= n ; i ++ ){
        int a ;
        cin >> a;
        add1(i, i , a);
    }
    while( q --){
        int op = 0;
        cin >> op;
        if(op == 1){
            int l ,r ,k;
            cin >> l >> r >> k;
            add1(l , r ,k);
        }
        else{
            int l , r ;
            cin >> l >> r;
            cout << getsum1(l , r)<< endl;
        }
    }

}