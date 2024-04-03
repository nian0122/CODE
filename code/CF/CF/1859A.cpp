#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t,n;

int main(){
    cin >> t;
    while(t --){
        cin >>n;
       vector<int> a(n);
        for(int i = 0;i < n;i++)
            cin >> a[i];
        
        sort(a.begin(),a.end());
        int maxv = a.back();
        vector<int> b,c;
        for(auto it = a.rbegin();it != a.rend();it++)
        {
            if(*it == maxv)c.push_back(*it);
            else b.push_back(*it);
        }
        
        if(c.size() != 0 &&b.size() != 0){
            cout << b.size() << " " << c.size() <<"\n";
            for(int i = 0;i < b.size();i++)
                cout << b[i] <<" ";
            cout << "\n" ;
            for(int i = 0;i < c.size();i ++)
                cout << c[i] <<" ";
            cout << "\n";
        }
        else cout<< "-1"<<"\n";

    }
return 0;

}
