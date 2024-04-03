#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<queue>//���� deque˫�˶��� priority_queue����� priority_queue<int,vector<int>,greater<int>>С����
#include<list>
#include<vector>
#include<numeric>
#include<stack>//ջ
#define endl '\n'
#define all(a) (a).begin(),(a).end()
#define sz(a) (a).size()
using namespace std;
const int N = 1e3 + 10;

int happy[N];
int h[N],e[N],ne[N],idx;
int f[N][2];
bool has_fa[N];

void add(int a,int b){
    e[idx] = b ,ne[idx] = h[a],h[a] = idx ++ ;
}

void dfs(int u){
    f[u][1] = happy[u];

    for(int i = h[u] ; i != -1 ;  i = ne[i]){
        int j = e[i];
        dfs(j);
        f[u][1] += f[j][0];
        f[u][0] += max(f[j][0],f[j][1]);
    }
}

int main(){
    int n ;
    cin >> n;
    for(int i = 1 ;i <= n;i ++){
        cin >> happy[i];
    }
    memset(h,-1,sizeof h);

    for(int i = 1;i < n;i ++){
        int l,k;
        cin >> l >> k;
        add(k,l);
        has_fa[l] = true;
    }
    int root = 1;
    while(has_fa[root]) root ++ ;
    dfs(root);
    cout << max(f[root][0],f[root][1])  << endl;
}