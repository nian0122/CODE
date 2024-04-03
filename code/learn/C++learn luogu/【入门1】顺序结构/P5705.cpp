#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    char a, b, c, d;
    scanf("%c%c%c.%c",&a,&b,&c,&d);
    printf("%c.%c%c%C",d,c,b,a); 
    
    return 0;
}