#include<iostream>
#include<vector>

using namespace std;

int m, n;
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
vector<vector<char>> map(101, vector<char>(101, 0));

void dfs(int x, int y) {
    // cout << x << ' ' << y << '\n';
    int newx ;
    int newy ;
    
    map[x][y] = '.';
    for (int i = 0; i < 8; i++) {
        newx = x + dx[i];
        newy = y + dy[i];
        // cout << newx << ' ' << newy << '\n';
        if (newx < 0 || newx > n || newy < 0 || newy > m) {
            continue;
        }
        if (map[newx][newy] == 'W') {
            dfs(newx, newy);
        }
    }
    return;
}

int main(){
    
    cin >> n >> m; 
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout <<  map[i][j];
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m ; j++) {
            if(map[i][j] == 'W'){
                dfs(i, j);
                ans++;
            }
            
        }
    }
    cout << ans << endl;
}