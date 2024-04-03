#include<iostream>

using namespace std;

const int N=10;

int n;
char g[N][N];
bool row[N],col[N],dg[N],udg[N];

void dfs(int x,int y,int s){
    if(y==n)y=0,x++;
    if(x==n){
        if(s==n){
            for(int i=0;i<n;i++)puts(g[i]);
            cout<<endl;
        }
        return;
    }

    dfs(x,y+1,s);

    if(!row[x]&&!col[y]&&!dg[x+y]&&!udg[x-y+n]){
        g[x][y]='Q';
        row[x]=col[y]=dg[x+y]=udg[x-y+n]=true;
        dfs(x,y+1,s+1);
        row[x]=col[y]=dg[x+y]=udg[x-y+n]=false;
        g[x][y]='.';
        
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)g[i][j]='.';

    dfs(0,0,0);
    return 0;
}
// char g[N][N];
// bool col[N],dg[N],udg[N];
// int n;

// void dfs(int u){
//     if(u == n){
//         for(int i = 0; i < n ; i++)puts(g[i]);   
//         cout<<endl;
//         return;
//     }
    
//     for(int i=0;i<n;i++){
//         if(!col[i]&&!dg[i+u]&&!udg[n-u+i]){
//             g[u][i]='Q';
//             col[i]=dg[u+i]=udg[n-u+i]=true;
//             dfs(u+1);
//             col[i]=dg[u+i]=udg[n-u+i]=false;
//             g[u][i]='.';
//         }
//     }

// }

// int main(){
//     cin>>n;
//     for(int i=0;i<n;i++)
//     for(int j=0;j<n;j++)g[i][j]='.';

//     dfs(0);

//     return 0;

// }