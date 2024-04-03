#include<cstdio>
using namespace std;
int main (){
    double water;
    int stu = 0;
    scanf("%lf %d",&water,&stu);
    printf("%.3lf\n%d",water/stu,stu*2);
    return 0;

}