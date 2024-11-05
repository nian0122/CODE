#include<iostream>

using namespace std;

double n,mid;

void bsearch(double n)
{
    double l=0,r=n;

    while(r-l>1e-8)//这里是一个查找的方法
    {
        mid=(l+r)/2;
        if(mid*mid>n)r=mid;
        else l=mid;
    }
}

int main()
{
    cin>>n;

    bsearch(n);
    
    cout<<mid;

    return 0;
}