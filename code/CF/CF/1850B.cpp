#include<iostream>
#include<algorithm>

using namespace std;
const int N = 60;

int re[N];

struct Response
{
    int c,q;
}response[N];

bool cmp1(const Response&a,const Response&b)
{
    return a.c < b.c;
}
bool cmp2(const Response&a,const Response&b)
{
    return a.q < b.q;
}

int main(){
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        for(int i = 0;i < n;i ++)
        {
            int c,q;
            cin >> c >> q;
            re[q] = i;
            response[i]={c,q};
        }
        sort(response,response + n,cmp1);

        int j = n - 1;
        while(response[j].c > 10)
        {
            j --;
        }
        sort(response,response + j + 1,cmp2);
        cout << re[response[j].q]+1 <<" \n";


    }

}