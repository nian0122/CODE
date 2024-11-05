#include<iostream>
#include<vector>

using namespace std;

int n;
int dx[8] = {-1,0,0,1};
int dy[8] = {0,-1,1,0};
vector<vector<int>> map(101, vector<int>(101, 0));
vector<vector<int>> nex(101, vector<int>(101, 0));

void dfs(int x, int y) {
    
    if (x < 0 || x > n + 1 || y < 0 || y > n + 1 || nex[x][y] != 0) {
        return;
    }
    // cout << x << ' ' << y << '\n';
    nex[x][y] = 1;
    int newx ;
    int newy ;
    for (int i = 0; i < 4; i++) {
        newx = x + dx[i];
        newy = y + dy[i];
        // cout << newx << ' ' << newy << '\n';
        dfs(newx, newy);
    }
    return;
}

int main(){
    
    cin >> n; 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if (map[i][j]==0) nex[i][j]=0;
            else nex[i][j]=2;
        }
    }
    dfs(0, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            if (nex[i][j]==0) cout<<2<<' ';//如果染过色以后i，j那个地方还是0，说明没有搜到，就是周围有墙，当然就是被围住了，然后输出2
            else cout<<map[i][j]<<' ';//因为被染色了，本来没有被围住的水和墙都染成了1，所以就输出b[i][j]
        cout<<'\n';//换行
    }
    //     for (int i = 0; i <= n + 1; i++){
    //     for (int j = 0; j <= n + 1; j++)
    //         cout << nex[i][j] ;    
    //     cout<<'\n';//换行
    // }
}