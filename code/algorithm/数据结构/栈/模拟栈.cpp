#include<iostream>

using namespace std;

const int N=1e6+10;

int stk[N];
int tt=0;

int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(s=="push"){
            int x;
            cin>>x;
            stk[++tt]=x;
        }
        if(s=="query")cout<<stk[tt]<<endl;
        if(s=="pop")tt--;
        if(s=="empty"){
            if(tt)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }

}