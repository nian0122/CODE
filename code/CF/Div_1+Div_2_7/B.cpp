#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 2e5 + 10;
int a[N];

int bfs(int i ,int a[]){
    int ans = 0;
    if(i <= 1){
        return ans;
    }
    if(a[i] == 0 && a[i + 1]){
        swap(a[i], a[i + 1]);
        ++ans;
        return ans + bfs(--i, a);
    }
}

int bfs_2(int i,int n,int a[]){
    int ans = 0;
    if(i >= n - 1){
        return ans;
    }
    if(a[i] == 0 && a[i + 1] == 1){
        swap(a[i], a[i + 1]);
        ++ans;
        return ans + bfs_2(++i, n, a);
    }
}

void work(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; ++i){
        a[i] = s[i] - 'A';
    }
    int ans = 0;
    for(int i = 0; i < n - 1; ++i){
        ans = max(ans, bfs(i, a) + bfs_2(i, n, a));
    }
    cout << ans << endl;    
}    


int main() {
    int t;
    cin >> t;
    while(t--)
        work();
    return 0;
}