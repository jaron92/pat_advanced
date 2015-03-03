#include <iostream>
#include <vector>
using namespace::std;

bool isPrime(int n){
	if (n==0 || n == 1){
		return false;
	}
	for (int i = 2; i*i <= n; i++){
		if (n%i == 0)
			return false;
	}
	return true;
}

int main(){
	int m, n;
	cin >> m >> n;
	while (!isPrime(m)){
		m++;
	}
	vector<int> table(m, -1);
	for (int i = 0; i < n; i++){
		int v;
		cin >> v;
		int j = v%m, k, po;
		for (k = 0; k < m; k++){
			po = (j + k*k) % m;
			if (table[po] == -1){
				table[po] = v;
				break;
			}
		}
		if (k == m){
			cout << '-';
		}
		else{
			cout << po;
		}
		if (i != n - 1)
			cout << ' ';
	}
	return 0;
}