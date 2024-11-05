#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cstring>
using namespace std;
char str[101];
const int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int maxn=0,minn=100,sum[26];
int main(){
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
        sum[str[i]-'a']++;
    for(int i=0;i<26;i++){
        if(sum[i]>maxn)maxn=sum[i];
        if(sum[i]>0&&sum[i]<minn)minn=sum[i];
    }
    for(int i=0;i<26;i++){
        if((maxn-minn)==prime[i]){
            printf("Lucky Word\n%d",maxn-minn);
            return 0;
        }
    }
    printf("No Answer\n0");
	return 0;
}