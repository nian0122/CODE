#include<iostream>

using namespace std;

const int N=1e5+10;

int q[N],cnt[N];
int n,m;

int find(int x){
    if(q[x] != x) q[x] = find(q[x]);
    return q[x];
}

int main(){
    cin >> n >> m;
    for (int i =1 ;i <= n; i ++){
        q[i] = i;
        cnt[i] = 1;
    }

    while( m -- ){
        char op[5];
        int a,b;
        scanf("%s",&op);
        // cout<<op[0];
        if(op[0]=='C'){
            scanf("%d%d",&a,&b);
            a = find(a), b = find(b);
            if(a!=b){
                q[a]=b;
                cnt[b]+=cnt[a];
                
            }
            
            // for(int i=0;i<=n;i++)cout<<cnt[i];
            // cout<<endl;
            // for(int i=1;i<=n;i++)cout<<q[i];
            
        }
        if(op[1]=='1'){
            scanf("%d%d",&a,&b);
            if(find(a)==find(b))cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            
        }
        if(op[1]=='2'){
            scanf("%d",&a);
            cout<<cnt[find(a)]<<endl;
        }
    
    }
    // for(int i=0;i<=n;i++)cout<<cnt[i];
    // cout<<endl;
    // for(int i=1;i<=n;i++)cout<<q[i];
    
        
}
// 5 5
// C 1 2
// Q1 1 2
// Q2 1
// C 2 5
// Q2 5