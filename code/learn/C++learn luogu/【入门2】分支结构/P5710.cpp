#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int x;
bool a, b;
int main(){
    cin>>x;
    a = !(x & 1), b = (x > 4 && x <= 12);
    printf("%d %d %d %d", a & b, a | b, (a && !b || b && !a), !a && !b);
}