#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int n;
struct student{
    string name;
    int a,b,c,id;
    int sum;
}stu[1001];
bool cmp(student x,student y)
{
	if(x.sum==y.sum)return x.id<y.id;
	return x.sum>y.sum;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>stu[i].name>>stu[i].a>>stu[i].b>>stu[i].c;
        stu[i].id=i;
        stu[i].sum = stu[i].a+stu[i].b+stu[i].c;
    }
    sort(stu + 1, stu + n + 1,cmp);
    cout<<stu[1].name<<" "<<stu[1].a<<" "<<stu[1].b<<" "<<stu[1].c;
    return 0;
}