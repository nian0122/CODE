#include<iostream>
#include<vector>

using namespace std;

vector<int> A,B,C;

bool cmp(vector<int> &A,vector<int> &B)
{
    if(A.size()!=B.size())return A.size()>B.size();

    for(int i=A.size()-1;i>=0;i--)
    {
        if(A[i]!=B[i])return A[i]>B[i];
    }
  
    return true;
}

vector<int>sub(vector<int> &A,vector<int> &B)
{
    vector<int> C;

    int t=0;

    for(int i=0;i<A.size();i++)
    {
        t=A[i]-t;
        if(i<B.size())t-=B[i];
        C.push_back((t+10)%10);
        if(t<0)t=1;
        else t=0;
    }

    while(C.size()>1&&C.back()==0) C.pop_back();

    return C;
}

int main()
{
    string a,b;

    cin>>a>>b;

    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');

    if(cmp(A,B))
    {
        auto C=sub(A,B);

        for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    }
    else
    {
        cout<<'-';

        auto C=sub(B,A);

        for(int i=C.size()-1;i>=0;i--)cout<<C[i];

    }

    return 0;

}
//有一个问题 容器如果size等于3，将他pop_back两位，他的size等于1，但是输出被删除的部分，他的值等于删除之前，如果输出4及在之前没有赋值，则是随机数
//总的来说，pop_back只是改变了size,被赋予的值没有改变，如果你输出被删除的部分，还是那个值