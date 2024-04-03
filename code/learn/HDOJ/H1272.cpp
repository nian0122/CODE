#include <iostream>  
using namespace std;  
int father[100005];  
bool flag ,visit[100005];  
int getfather(int n)  
{  
    while(n!=father[n])  
        n = father[n];  
    return n;  
}  
void myunion(int x,int y)  
{  
    int a = getfather(x);  
    int b = getfather(y);  
    if(a!=b)father[a] = b;  
    else flag = false;  
}  
int main()  
{  
    int n,m;  
    int num;  
    while(cin>>n>>m)  
    {  
        if(n==-1&&m==-1)break;  
        if(n==0&&m==0){cout<<"Yes"<<endl;continue;}  
        for(int i=1;i<100005;i++)  
        {  
            father[i] = i;  
            visit[i] = 0;  
        }  
        visit[n] = visit[m] = 1;  
        flag = 1;  
        myunion(n,m);  
        while(cin>>n>>m)  
        {  
            if(n==0&&m==0)break;  
            myunion(n,m);  
            visit[n] = visit[m] = 1;  
        }  
        num=0;  
        for(int i=1;i<100005;i++)  
        {  
            if(visit[i]&&father[i]==i)num++;  
            if(num>1)flag=0;  
        }  
        if(flag)cout<<"Yes"<<endl;  
        else cout<<"No"<<endl;  
    }  
    return 0;  
}   