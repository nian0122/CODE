#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void solve(){
    string s;
    for(int i = 3; i > 0; i--){
        cin >> s;
        for(int j = 0; j < 3; j++){
            if(s[j] == '?'){
                sort(s.begin(),s.end());
                // for (int  z = 0; z < 3; z++){
                //      cout << s[z] ;
                // }
                // cout << endl;
                if(s[1] == 'A'){
                    if(s[2] == 'B'){
                        cout << 'C' << endl;
                    }else{
                        cout << 'B' << endl;
                    }
                }else{
                    cout << 'A' << endl;
                }
            }
        }
    }
}

int main(){
    int __;
    cin >> __;
    while(__--){
        solve();
    }
}