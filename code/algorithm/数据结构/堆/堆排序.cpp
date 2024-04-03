#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e5+10;

int n,m;
int heap[N],cnt;

void down(int u){
    int t=u;
    if(2*t<=cnt&&heap[2*t]<heap[t])t=2*u;
    if(2*t+1<=cnt&&heap[2*t+1]<heap[t])t=2*u+1;
    if(t!=u){
        swap(heap[t],heap[u]);
        down(t);
    }
}

void up(int u){
    while(u/2&&heap[u]<heap[u/2]){
        swap(heap[u],heap[u/2]);
    }

}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&heap[i]);
    cnt=n;

    for(int i=n/2;i;i--)down(i);

    while(m--){
        printf("%d ",heap[1]);
        heap[1]=heap[cnt--];
        down(1);
    }
}
// 5 3
// 4 5 1 3 2
