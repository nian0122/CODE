#include<iostream>

using namespace std;

const int N=1e6+10;

int l[N],r[N],vel[N];
int n,head,tail,id;

void init(){
    l[1]=0;
    r[0]=1;
    id=2;
    tail=1;
    head=0;
}
void add(int k, int x){
    vel[id]=x;
    l[id]=k;
    r[id]=r[k];
    l[r[k]]=id;
    r[k]=id;
    id++;
}

void remove(int k){
    r[l[k]]=r[k];
    l[r[k]]=l[k];
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    init();
    cin>>n;
    while(n--){
        string s;
        int x,k;
        cin>>s;
        if(s=="L"){
            cin>>x;
            add(0,x);
        }
        if(s=="R"){
            cin>>x;
            add(l[tail],x);
        }
        if(s=="D"){
            cin>>k;
            remove(k+1);
        }
        if(s=="IL"){
            cin>>k>>x;
            add(l[k+1],x);
        }
        if(s=="IR"){
            cin>>k>>x;
            add(k+1,x);
        }
    }
    for(int i=r[0];i!=1;i=r[i])cout<<vel[i]<<" ";

}