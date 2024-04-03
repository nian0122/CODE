#include<iostream>
#include<cstdio>
using namespace std;
int a, b, c, d, t ,h, m;
int main(){
    cin>>a>>b>>c>>d;
    if (a == 0 && b == 0 && c == 0 && d == 0)cout<<"24 0"<<endl;
    else{
    h = c -a -1;
    m = 60 -b + d;
    if(m >= 60 ){
        h += m /60;
        while (m>=60)
        {
           m -=60;
        }
    }
    cout<<h<<" "<<m<<endl;    
    }    
    return 0;
}