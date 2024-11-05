#include<iostream>
#define int long long

using namespace std;
const int N = 1e6 + 10;
int n , q;
int a[N], c[N];

void add(int x ,int k){
    for (int i = x; i <= n; i += (i & -i)) {
        c[i] += k;
    }
}

int getsum(int x){
    int ans = 0;
    for(int i = x; i > 0; i -= (i & -i)){
        ans += c[i];
    }
    return ans;
}

int32_t main(){
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i];
        add(i , a[i] - a[i - 1]);
    }
    while(q--){
        int op = 0;
        cin >> op;
        if(op == 1){
            int x , y , k;
            cin >> x >> y >> k ;
            add(x , k);
            add(y + 1 , -k);
        }
        else {
            int x ;
            cin >> x;
            cout << getsum(x) << endl;
        }
    }

}