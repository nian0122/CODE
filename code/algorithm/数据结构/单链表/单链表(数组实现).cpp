#include<iostream>

using namespace std;

const int N=1e6+10;

int head ,vel[N] ,idx ,nod[N];

//≥ı ºªØ
void init(){
    head=-1;
    idx=0;
}

void into_head(int x){
    vel[idx]=x;
    nod[idx]=head;
    head=idx;
    idx++;
}

void add(int k,int x){
    vel[idx]=x;
    nod[idx]=nod[k];
    nod[k]=idx;
    idx++;
}

void del(int k){
    nod[k]=nod[nod[k]];
}

int main()
{
    int n;
    scanf("%d",&n);
    init();
    for (int i = 1; i <=n; i ++ ) {
        char c[2];
        scanf("%s",c);
        if (c[0] == 'H') {
            int k;
            scanf("%d",&k);
            into_head(k);
        }
        
        else if (c[0] == 'D'){
            int k;
            scanf("%d",&k);
            if (k == 0) head = nod[head];
            else del(k-1);
        }

        else if (c[0] == 'I'){
            int k;
            int x;
            scanf("%d %d",&k,&x);
            add(k-1,x);
        }
        
    }
    
    for (int i = head; i != -1; i = nod[i]) cout << vel[i] << ' ' ;
    return 0;
}
