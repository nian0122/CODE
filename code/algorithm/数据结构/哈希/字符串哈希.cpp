#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e5+10 , P=131;
typedef unsigned long long ULL;

int n,m;
char str[N];
ULL h[N],p[N];

ULL get(int l,int r){//l到r之间的哈希
    return h[r]-h[l-1]*p[r-l+1];//p表示进位缺多少乘多少
}

int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);

    p[0]=1;
    for(int i=1;i<=n;i++){//前缀哈希
        h[i]=h[i-1]*P+str[i];
        p[i]=p[i-1]*P;
    }

    while(m--){
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);

        if(get(l1,r1)==get(l2,r2))puts("Yes");
        else puts("No");
    }
}
// 8 3
// aabbaabb
// 1 3 5 7
// 1 3 6 8
// 1 2 1 2