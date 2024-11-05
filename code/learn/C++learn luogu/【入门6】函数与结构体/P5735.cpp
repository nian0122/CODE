#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
double x1, y_1, x2, y2, x3, y3, c,dis1,dis2,dis3;
double dis(double x1, double y1, double x2, double y2)
{
	return sqrt(abs((x1 - x2) * (x1 - x2)) + abs((y1 - y2) * (y1 - y2)));
}
int main(){
    cin >> x1 >> y_1 >> x2 >> y2 >> x3 >> y3;
	dis1 = dis(x1, y_1, x2, y2);
    dis2 = dis(x2, y2, x3, y3);
    dis3 = dis(x3, y3, x1, y_1);
	c = dis1 + dis2 + dis3;
	printf("%.2f", c);
    return 0;
}
