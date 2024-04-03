#include<iostream>

using namespace std;

const int N=1e6+10;

int q[N];
int tt=-1,hh=0;

int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(s=="push"){
            int x;
            cin>>x;
            q[++tt]=x;
        }
        if(s=="pop")hh++;
        if(s=="empty"){
            if(hh<=tt)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        if(s=="query")cout<<q[hh]<<endl;
    }
    return 0;
}