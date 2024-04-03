#include<iostream>
#include<vector>

using namespace std;
const int N = 400;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n, m, x, y;
vector<vector<int>> map(N + 1, vector<int>(N + 1, -1));

struct queue
{
    int nx;
    int ny;
} que[160010];
int head = 0, tail = 1; 

void bfs()
{
    while(head < tail) {

        head++;
        int s = map[que[head].nx][que[head].ny] + 1;
//        cout << ";" << x << " " << y << endl;
        for (int i = 0; i < 8; i++) {
            int newx, newy;
            newx = que[head].nx + dx[i];
            newy = que[head].ny + dy[i];
            if (newx > 0 && newx <= n && newy > 0 && newy <= m && map[newx][newy] == -1) {
                tail++;
                que[tail].nx = newx;
                que[tail].ny = newy;
                map[newx][newy] = s;
            }

        }
    }
}

int main() {
    cin >> n >> m >> x >> y;
    map[x][y] = 0;
    que[1].nx = x;
    que[1].ny = y;
    bfs();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << map[i][j] << "    ";
        }
        cout << endl;
    }
    return 0;
}