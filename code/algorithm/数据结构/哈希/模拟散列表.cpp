#include<iostream>
#include<cstring>

using namespace std;
//拉链法
// const int N=100003;

// int e[N],ne[N],idx,head[N];

// void insert(int x){
//     int k=(x%N+N)%N;
//     e[idx]=x;
//     ne[idx]=head[k];
//     head[k]=idx;
//     idx++;
// }

// bool find(int x){
//     int k=(x%N+N)%N;
//     for(int i=head[k];i != -1; i=ne[i])
//     if(e[i] == x)return true;
//     return false;
// }

// int main(){
//     int n;
//     scanf("%d",&n);
//     memset(head, -1, sizeof head);

//     while(n--){
//         char op[2];
//         int x;
//         scanf("%s%d",op,&x);

//         if(*op == 'I')insert(x);
//         else{
//             if(find(x))puts("Yes");
//             else puts("No");
//         }
//     }
// }


//开放寻址法
const int N=200003,null=0x3f3f3f3f;

int h[N];

int find(int x){
    int k=(x%N+N)%N;
    while(h[k] != null && h[k] != x){
        k++;
        if(k== N)k=0;
    }
    return k;
}

int main(){
    int n;
    scanf("%d",&n);
    memset(h, 0x3f, sizeof h);

    while(n--){
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if(*op == 'I')h[find(x)]=x;
        else {
            if(h[find(x)]==null)puts("No");
            else puts("Yes");
            //cout<<find(x);
        }
    }
    // for(int i=0;i<=4;i++)cout<<h[i]<<endl;
}
// 5
// I 1
// I 2
// I 2
// Q 2
// Q 5