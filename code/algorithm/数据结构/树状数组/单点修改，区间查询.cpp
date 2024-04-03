#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N] , c[N];

int lowbit(int x){
    return x & -x;
}

void add(int x , int k){
    while(x <= n){
        c[x] = c[x] + k;
        x = x + lowbit(x);
    }
}

int getsum(int x){
    int ans = 0;
    while (x > 0)
    {
        ans = ans + c[x];
        x = x - lowbit(x);
    }
    return ans ;
}

int main(){
    int q ;
    cin >> n >> q;
    for(int i = 1 ;i <= n ; i ++){
        cin >> a[i] ;
        add(i , a[i]);
    }

    for(int i = 1 ; i <= q ; i ++){
        int op = 0;
        cin >> op;
        int x , y ;
        if ( op == 1){
            cin >> x >> y ;
            add(x , y);
        }
        else {
            cin >> x >> y ;
            cout << getsum(y) - getsum(x - 1) << endl;
        }
    }
}
