#include<iostream>

using namespace std;

const int N=1e5+10;

int n,m;
int p[N];

int find(int x){//Ѱ��Ԫ��ָ���ͷ
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
            p[find(a)]=find(b);//�����������ȫ��ָ��ͷ ֻҪԪ��ָ���ͷ��ͬ ����ͬһ������
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