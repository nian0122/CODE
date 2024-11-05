#include<iostream>

using namespace std;

const int N=1e5+10;

//son�ӽڵ� cnt�ַ�������λ����p,idx��� idx��¼��ͬ�ڵ�����������½ڵ� p��������һ���ڵ�
int son[N][26],cnt[N],idx;
char str[N];

void insert(char str[]){
    int p = 0;
    for(int i=0;str[i];i++){
        int u = str[i]-'a';
        if(!son[p][u])son[p][u]=++idx;
        p=son[p][u];
    }
    cnt[p]++;
}

int query(char str[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u])return 0;
        p=son[p][u];
    }
    return cnt[p];
}

int main(){
    int n;
    cin>>n;
    while(n--){
        char s,str[N];
        cin>>s>>str;
        if(s=='I')insert(str);
        else cout<<query(str)<<endl;
    }
        // for(int i=0;i<5;i++){
        
        // for(int j=0;j<10;j++)cout<<son[i][j];
        // cout<<" "<<cnt[i]<<endl;
        // }
}
// 5
// I abc
// Q abc
// Q ab
// I abf
// Q ab