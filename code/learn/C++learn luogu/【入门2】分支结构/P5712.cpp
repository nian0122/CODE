#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
int main(){
    cin>>n;
	if(n==1 || n==0) cout<<"Today, I ate "<<n<<" apple.";
	else cout<<"Today, I ate "<<n<<" apples.";
	return 0;
}