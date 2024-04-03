#include <iostream>
#include <iomanip>

int used[10];
int ans[10];
int n;

void print(){
    int i;
    for (i = 1; i <= n; i++){
        std::cout << std::setw(5) << ans[i];
    }
    std::cout << std::endl;
}

void dfs(int step){
    if (step == n){
        print();
        return;
    }
    int i;
    for(i = 1;i <= n; i++){
        if(!used[i]){
            used[i] = 1;
            ans[step + 1] = i;
            dfs(step + 1);
            used[i] = 0;
        }
    }

}

int main (){
    std::cin >> n;
    dfs(0);
}