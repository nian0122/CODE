#include<iostream>
#include <cstdint>
#define int long long

using namespace std;

void solve(){
	int n, p, l, t;
	cin >> n >> p >> l >> t;
	int cont = (n -1) / 7 + 1;
	int left = 0, right = n, mid = left + (right-left)/2,ans = 0;
	int id = 0;
	while (left < right) {
		// cout << id++ <<":" << left << " "<< right << " " << mid <<endl;
		mid = left + (right-left)/2;
		ans = mid * l;
		int task = min(cont, mid * 2);
		ans += task * t;
		if (ans >= p) right = mid;		 
		else left = mid + 1;
	}
	int fin = n - right;
	cout << fin << '\n';
}   
int32_t main() {
	int __;
	cin >> __;
	while (__--) {
		solve();
	}
}