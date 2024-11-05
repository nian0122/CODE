#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=1e5+10; 

int n,m=0;//heap特点：数组存放堆值下标对应值的位置
int heap[N],cnt,hp[N],ph[N];//ph存放堆值的下标 hp存放堆值的映射

void heap_swap(int a ,int b){
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(heap[a],heap[b]);
    // cout<<ph[a]<<ph[b]<<endl;
    // cout<<hp[a]<<hp[b]<<endl;
    // cout<<heap[a]<<heap[b]<<endl;

}

void down(int u){
    int t=u;
    if(2*t<=cnt&&heap[2*t]<heap[t])t=2*u;
    if(2*t+1<=cnt&&heap[2*t+1]<heap[t])t=2*u+1;
    if(t!=u){
        heap_swap(u,t);
        down(t);
    }
}

void up(int u){
    while(u/2&&heap[u]<heap[u/2]){
        heap_swap(u,u/2);
        u >>= 1;
    }

}

int main(){
    scanf("%d",&n);
    while(n--){
        char op[5];
        int k,x;
        scanf("%s",op);
        if(!strcmp(op,"I")){
            scanf("%d",&x);
            cnt++;
            m++;
            ph[m]=cnt,hp[cnt]=m;
            heap[cnt]=x;
            up(cnt);
        }
        if(!strcmp(op,"PM"))printf("%d\n",heap[1]);
        if(!strcmp(op,"DM")){
            heap_swap(1,cnt);
            cnt--;
            down(1);
        }
        if(!strcmp(op,"D")){//删除堆值首先要找到值对应的下标（ph）调换该值与堆尾 再排序
            scanf("%d",&k);
            k=ph[k];
            heap_swap(k,cnt);
            cnt--;
            up(k);
            down(k);
        }
        if(!strcmp(op,"C")){
            scanf("%d%d",&k,&x);
            k=ph[k];
            heap[k]=x;
            up(k);
            down(k);
        }
    }
// cout<<cnt<<endl;
// for(int i=1;i<=cnt;i++)cout<<heap[i]<<" ";
// for(int i=1;i<=cnt+1;i++)cout<<hp[i]<<" ";
// for(int i=1;i<=cnt+1;i++)cout<<ph[i]<<" ";
// for(int i=1;i<=cnt;i++)cout<<heap[ph[hp[i]]]<<" ";
// for(int i=1;i<=cnt+1;i++)cout<<ph[hp[i]]<<" ";
}
// 8
// I -10
// PM
// I -10
// D 1
// C 2 8
// I 6
// PM
// DM