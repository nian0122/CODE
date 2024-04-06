#include<bits/stdc++.h>
using namespace std;
struct Node {
    int x, y;
};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n;
queue<Node> q;
int v[305][305],vi[305][305],vim[305][305];
int ch(int a) {
    if(a == -1) return 9999;
    return a;
}
void bfs(){
    q.push({0, 0});
    v[0][0] = 1;
    while(!q.empty()){
        Node u = q.front();
        q.pop();
        int t = vi[u.x][u.y] + 1;      
        if(vim[u.x][u.y] == -1) {
            cout << t - 1;
            return;
        }
        int newx,newy;
        for(int i = 0; i < 4; i++) {
            newx = u.x + dx[i];
            newy = u.y + dy[i];
            if(newx >= 0 &&newx < n && newy >= 0 && newy < n && t < ch(vim[newx][newy]) && v[newx][newy] == 0) {
                q.push({newx, newy});
                v[newx][newy] = 1;
                vi[newx][newy] = t;
            } 
        }       
    }
    cout << -1 << endl;

}
void solve() {
    for (int i=0;i<305;i++){
    	for (int j=0;j<305;j++){
    		vim[i][j]=-1;
		}
	}
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        vim[a][b] = c;
        for(int i = 0; i < 4; i++) {
            int new_x = a + dx[i];
            int new_y = b + dy[i]; 
            if(new_x >= 0 &&  new_x < n && new_y >= 0 && new_y < n && (vim[new_x][new_y] == -1 || vim[new_x][new_y] > c)) {
                vim[new_x][new_y] = c;
            }
        }        
    }
    //     for(int i = 0; i < n + 1; i++){
    //     for(int j = 0; j < n + 1; j++){
    //         cout << vim[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    bfs();
}
int main() {
    solve();
}