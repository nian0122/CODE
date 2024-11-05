#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> A,B;
int b;

vector<int>div(vector<int> &A,int b ,int &t)
{
    t=0;
    for(int i=A.size()-1;i>=0;i--)
    {
        t=t*10+A[i];
        B.push_back(t/b);
        t%=b;
    }

    reverse(B.begin(),B.end());

    while(B.size()>1&&B.back()==0)B.pop_back(); 

    return B;

}

int main()
{
    string a;
    int b,t;

    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');

    auto B=div(A,b,t);

    for(int i=B.size()-1;i>=0;i--)cout<<B[i];
    cout<<endl<<t;

    return 0;
}