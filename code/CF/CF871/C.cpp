#include<iostream>

using namespace std;

void solve(){
     int n;
     cin >> n;
     int a , A = 0x3f3f3f3f , B = 0x3f3f3f3f , C =0x3f3f3f3f;
     string s;
     bool flage_1 = false,flage_2 = false ,flage_3 = false;
     for(int i = 0 ;i < n ; i ++){
        cin >> a >> s;
        if(s == "10"){
            flage_1 = true;
            A = min(A ,a);
        }
        if(s == "01"){
            flage_2 = true;
            B = min(B,a);
        }
        if(s == "11"){
            flage_3 = true;
            C = min(C,a);
        }
     }
     if(flage_3 || (flage_1 && flage_2)){
        int ans = min(A + B , C);
        cout << ans << endl;
     }
     else{
        cout << -1 << endl;
     }
     
}

int main(){
    int t;
    cin >> t ;
    while(t --){
        solve();
    }
}