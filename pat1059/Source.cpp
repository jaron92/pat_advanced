#include <iostream>
using namespace::std;

bool isPrime(long n){
	for (long i = 2; i*i <= n; i++){
		if (n % i == 0)
			return false;
	}
	return true;
}

int main(){
	long n;
	cin >> n;
	long tmp = n, k = 0;
	cout << n << '=';
	if (n == 1)
		cout << n;
	for (long i = 2; i <= tmp; i++){
		if (isPrime(i)){
			k = 0;
			while (i <= n&&n%i == 0){
				k++;
				n /= i;
			}
			if (k>1)
				cout << i << '^' << k;
			if (k == 1)
				cout << i;
			if (n != 1 && k != 0)
				cout << '*';
		}
		if (n == 1)
			break;
	}
	return 0;
}