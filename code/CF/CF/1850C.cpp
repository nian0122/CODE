#include<iostream>
#include<vector>

using namespace std;

const int N = 10;

char map[N][N];
string s[N];
int t;

int main(){
    cin >> t;
    while(t-- )
    {
        vector<char> ans;
        for(int i = 0;i < 8;i ++)
        {
            scanf("%s",map[i]);
        }
        // for(int i = 0;i < 8;i ++)
        // {
        //     printf("%s\n",map[i]);
        // }
        for(int i = 0;i < 8;i ++)
        {
            for(int j = 0;j < 8;j ++)
            {
                if(map[i][j] >= 'a' && map[i][j] <= 'z')
                {
                    ans.push_back(map[i][j]);
                }
            }
        }
        for(int i = 0;i < ans.size();i ++)
        {
            cout << ans[i];
        }
        cout << "\n";
    }

}