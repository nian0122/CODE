#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int n;
struct student{
    string a;
    int age;
    int sore;
}stu[6];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>stu[i].a>>stu[i].age>>stu[i].sore;
    for(int i=1;i<=n;i++){
        stu[i].age +=1;
        stu[i].sore*=1.2;
        if(stu[i].sore>600)stu[i].sore=600;
    }
    for(int i=1;i<=n;i++)cout<<stu[i].a<<" "<<stu[i].age<<" "<<stu[i].sore<<endl;
    return 0;
}