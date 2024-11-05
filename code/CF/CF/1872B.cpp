#include<iostream>

using namespace std;

const int N = 110;

int main(){
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        int k = 0x3f3f3f;
        for(int i = 0;i < n;i ++ )
        {
            int b,s;
            cin >> b >> s;
            k = min(k ,(s - 1) / 2 + b);
        }
        cout << k << '\n';

    }
}