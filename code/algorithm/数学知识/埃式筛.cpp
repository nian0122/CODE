#include<bits/stdc++.h>
using namespace std;
const long long N = 1000000;
long long is[N];
void isPrimes(int n){
	for(int i = 2; i * i <= n; i++){
		if(is[i] == 1){
			continue;
		}
		for(long long j = i * i; j < n; j+= i){
			is[j] = 1;
		}
	}
}