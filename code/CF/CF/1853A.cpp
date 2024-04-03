#include<iostream>
#include<vector>
#include<algorithm>//min_element
#include<numeric>//adjacent_difference相邻之间的差值

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        vector<int> a(n),b(n);
        for(int i = 0;i < n;i++)
        {
            cin >> a[i];
        }

        adjacent_difference(a.begin(),a.end(),b.begin());

        int minv = *min_element(b.begin()+1,b.end());

        if(minv < 0)cout << 0 <<"\n";
        else cout << minv /2 + 1 <<"\n";

    }
}