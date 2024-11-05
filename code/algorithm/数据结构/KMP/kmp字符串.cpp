#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int N=1e6+10;

int ne[N];
char s[N],q[N];

void get_next(char q[],int m)
{   
    ne[0]=0;
    int i=1,j=0;
    while(i<m)
    {   
        if(q[i]==q[ne[j]])j++,ne[i]=j,i++;
        else if (j==0)ne[i]=0,i++;
        else j=ne[j-1];
    }
}

int main()
{
    int n,m;
    cin>>n>>q>>m>>s;
    get_next(q,n);

    for(int i=0,j=-1;i<m;i++){
        while(j != -1&&s[i]!=q[j+1])j=ne[j];
        if(s[i]=q[j+1])j++;
        if(j==n-1){
            printf("%d ",i-j);
            j=ne[j];
        }
    }
    return 0;
}
