#include<iostream>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    for (int  i = 0, j = s.size() - 1;i<j; ){
        if(s[i] == s[j] ) {
            i++;
            j--;
            
        }else if (s[i] < s[j])
        {
            cout << s << endl;
            return;
        }else 
        {
            for(int z = s.size() - 1; z >= 0; z--){
                cout << s[z];
            }
            cout << s ;
            cout << endl;
            return;
        }   
    }
    cout << s << endl;

}

int main () {
    int __;
    cin >> __;
    while (__--) {
        solve();
    }
}