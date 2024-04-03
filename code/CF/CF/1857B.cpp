#include <iostream>

using namespace std;
const int N = 1e5+10;
int ex[N], ans[N];

void slove()
{
    string s;cin>>s;
    s='0'+s;
    int p=s.size();
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]>='5')s[i-1]++,p=i;
    }
    for(int i=(s[0]=='0');i<s.size();i++)
    {
        cout<<(i>=p?'0':s[i]);
    }
    cout<<"\n";

}

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        slove();
    }
}