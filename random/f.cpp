#include <bits/stdc++.h>
// #define int long long
using namespace std;
// + 43 - 45 \ 92 | 124 / 47 . 46
int Ans = INT16_MIN;
char ve[55][55];
int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,1,-1,0,1};
int flag[8];
int n , m;
char c[8] = { '-', '\\','|', '/', '-', '\\', '|', '/' };

int LEN(int x,int y,int i){
	int l = 0;
	while(ve[x][y] == c[i]){
		l++;
        x += dx[i];
        y += dy[i];
		if(x < 0 || y < 0 || x >= n || y >= m){
			break;
		}
	}
	return l;
}

void dfs(int x,int y){
	if(x < 0 || y < 0 || x >= n || y >= m){
        return;
    }
	for(int i = 0; i < 8; i++){
		int nex = x + dx[i];
		int ney = y + dy[i];
		if(ve[nex][ney] == c[i]){
			flag[i] = LEN(nex,ney,i);
		}
		if(flag[i] == 0){
			return;
		}
	}
}


int ans(){
	int min = INT16_MAX;
	for(int i = 0; i < 8; i++){
		if(min > flag[i]){
			min = flag[i];
		}
		flag[i] = 0;
	}
	return min;
}

int main(){

	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
            cin >> ve[i][j];
        }
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(ve[i][j] == '+'){
				dfs(i,j);
				Ans = max(Ans,ans());
			}
		}
	}
	cout << Ans << endl;
    return 0;
}