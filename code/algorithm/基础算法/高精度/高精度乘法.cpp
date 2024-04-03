#include<iostream>
#include<vector>

using namespace std;

vector<int> A,B;

vector<int> mul(vector<int> &A,int b)
{
    int t=0;
    for(int i=0;i<A.size()||t;i++)
    {   
        if(i<A.size())t=b*A[i]+t;
        B.push_back(t%10);
        t/=10;
    }
    while(B.size()>1&&B.back()==0)B.pop_back(); 

    return B;
}

// vector<int> mul(vector<int> &A,int b)  自己想的
// {
//     int t=0;
//     for(int i=0;i<A.size();i++)
//     {   
//         t=b*A[i]+t;
//         B.push_back(t%10);
//         t/=10;
//     }
//     B.push_back(t);
//     while(B.size()>1&&B.back()==0)B.pop_back(); 

//     return B;
// }

int main()
{
    string a;
    int b;

    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');

    auto B=mul(A,b);

    for(int i=B.size()-1;i>=0;i--)cout<<B[i];

    return 0;

}