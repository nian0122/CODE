#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int n;
struct student{
    string name;
    int a, b, c;
    int sum;
}stu[1001];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>stu[i].name>>stu[i].a>>stu[i].b>>stu[i].c;
        stu[i].sum = stu[i].a+stu[i].b+stu[i].c;
    }
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int stuns=abs(stu[i].a-stu[j].a);//ÿһ�ŷ������
			int stuns1=abs(stu[i].b-stu[j].b);
			int stuns2=abs(stu[i].c-stu[j].c);
			int stuns3=abs(stu[i].sum-stu[j].sum);//�ܷ����
			if(stuns<=5&&stuns1<=5&&stuns2<=5&&stuns3<=10){//�ж��Ƿ��������൱�Ķ���
				if(stu[i].name>stu[j].name)//�ж��ֵ���
				cout<<stu[j].name<<" "<<stu[i].name<<"\n";
				else cout<<stu[i].name<<" "<<stu[j].name<<"\n";
			}
		}
	}
    return 0;
}