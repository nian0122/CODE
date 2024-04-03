#include<iostream>

using namespace std;

const int N=1e5+10;

int n,m;
int p[N];

int find(int x){//寻找元素指向的头
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}

int main(){
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)p[i]=i;

    while(m--){
        char op[2];
        int a,b;
        scanf("%s%d%d",op,&a,&b);

        if(op[0]=='M'){
            p[find(a)]=find(b);//将集合里的数全部指向头 只要元素指向的头相同 则在同一个集合
            // for(int i=1;i<=n;i++)cout<<p[i];
            // cout<<endl;
        }
        else{
            if(find(a)==find(b))puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
// 4 5
// M 1 2
// M 3 4
// Q 1 2
// Q 1 3
// Q 3 4