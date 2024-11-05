#include<iostream>

using namespace std;

const int N=1e6+10;

int n,m,res;

int lowbit(int m)
{
    return m&(-m);
}

int main(){
    int a = lowbit(4);
    cout << a << endl;
}
// int main()
// {
//     cin>>n;

//     while(n--)
//     {
//         cin>>m;
//         res=0;

//         while(m)
//         {
//             m-=lowbit(m);
//             res++;
//         }
//         cout<<res<<" ";
//     }
//     return 0;
// }