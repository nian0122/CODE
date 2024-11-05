#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int n;
char c[10][5][4]=
{
	"XXX",
	"X.X",
	"X.X",
	"X.X",
	"XXX",
	"..X",
	"..X",
	"..X",
	"..X",
	"..X",
	"XXX",
	"..X",
	"XXX",
	"X..",
	"XXX",
	"XXX",
	"..X",
	"XXX",
	"..X",
	"XXX",
	"X.X",
	"X.X",
	"XXX",
	"..X",
	"..X",
	"XXX",
	"X..",
	"XXX",
	"..X",
	"XXX",
	"XXX",
	"X..",
	"XXX",
	"X.X",
	"XXX",
	"XXX",
	"..X",
	"..X",
	"..X",
	"..X",
	"XXX",
	"X.X",
	"XXX",
	"X.X",
	"XXX",
	"XXX",
	"X.X",
	"XXX",
	"..X",
	"XXX"
},ans[10][1000];
int main(){
    cin>>n;
    int a,s=0;
    while(n--){
        scanf("%1d",&a);
        for(int i=0;i<5;i++)
			for(int j=0;j<3;j++)
				ans[i][s+j]=c[a][i][j];
		for(int i=0;i<5;i++) ans[i][s+3]='.';
		s+=4;
    }
    for(int i=0;i<5;i++){
		for(int j=0;j<s-1;j++) printf("%c",ans[i][j]);
		printf("\n");
	}
    return 0;
}