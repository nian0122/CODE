#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
char a[14], p[12]="0123456789X";
int j=1,s=0;
int main(){
    scanf("%c-%c%c%c-%c%c%c%c%c-%c",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9]);
    for(int i = 0; i < 9; i++)s += (a[i]-'0')*j++; 
     if(p[s%11] == a[9]) printf("Right");
  else {
    a[9] = p[s%11];
    printf("%c-%c%c%c-%c%c%c%c%c-%c",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
      
  }
  return 0;
}