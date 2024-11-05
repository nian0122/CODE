#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int q,a,b,n;
string str,ab;
int main(){
    cin>>q>>str;
    while(q--){
        cin>>n;
        if(n==1){
            cin>>ab;
            str += ab;
            cout<<str<<endl;
        }
        if(n==2){
            cin>>a>>b;
			string e=str;
			str="";
			for(int i=a;i<(e.length(),a+b);i++)
			str+=e[i];
            cout<<str<<endl;
        }
        if(n==3){
            string x="";
            cin>>a>>ab;
            for(int i=0;i<a;i++)x += str[i];
            x += ab;
            for(int i=a;i<str.length();i++)x += str[i];
            str = x;
            cout<<str<<endl;
        }
        if(n==4){
        cin>>ab;
			if(str.find(ab)<100)
			cout<<str.find(ab)<<endl;
			else
			cout<<-1<<endl;
        }
    }
    
    return 0;
}