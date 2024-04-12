#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int> q;
    deque<int> p;
    for(int i = 1; i <= 10; i++){
        q.push(i);
        p.push_front(i);
    }
    for(int i = 1; i <= 10; i++){
        int a= q.front();
        q.pop();
        int b = p.front();
        p.pop_front();
        cout << a << " "<< b << endl;
    }
}