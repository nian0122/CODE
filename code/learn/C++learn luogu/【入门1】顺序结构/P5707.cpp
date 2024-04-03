#include<iostream>
#include<cstdio>
using namespace std;
int s, v, t, h, m;
int main (){
    cin>>s>>v;
    if(s%v == 0)t = s / v +10;
    else t = s/v + 11; 
    if(t == 1440)printf("08:00");
    else
    {
    t = 1440 - t;
    h = t / 60;  
    while (t > 60)
    {
       t %= 60;
    }   
    if (h >= 16){
        h -= 16;
        printf("%02d:%02d",h,t);
    }
    else{
        printf("%02d:%02d",8 + h,t);
    }
    }
    
    return 0;
}