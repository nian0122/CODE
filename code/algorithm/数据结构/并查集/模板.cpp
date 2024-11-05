#include <bits/stdc++.h>
using namespace std;
vector<int> fa;
void init(int n) {
    fa.resize(n);
    for(int i = 0; i < n; i++) fa[i] = i;
}
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

int find(int x)
{
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}

void unionSet(int i, int j) {
    int x = find(i);
    int y = find(j);
    if(x != y) fa[x] = y;
}
