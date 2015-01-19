#include <iostream>

using namespace::std;

int a[100];

bool isPrime(int a){
	if (a == 1 || a == 0){
		return false;
	}
	int i;
	for (i = 2; i*i <= a; i++){
		if (a%i == 0)
			break;
	}
	if (i*i > a)
		return true;
	else
		return false;
}

int main(){
	int n, d, reverse, coe, tmp, count;
	while (true){
		cin >> n;
		if (n < 0)
			break;
		cin >> d;
		count = 0;
		tmp = n;
		while (n != 0){
			a[count++] = n % d;
			n /= d;
		}
		reverse = 0;
		coe = 1;
		for (int i = count - 1; i >= 0; i--){
			reverse += coe*a[i];
			coe *= d;
		}
		if (isPrime(reverse)&&isPrime(tmp))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}