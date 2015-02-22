#include <iostream>
using namespace::std;

int main()
{
	int n;
	cin >> n;
	int base = 1, sum = 0;
	while (n / base){
		int left = n / base / 10;
		int mid = n / base % 10;
		int right = n%base;
		if (mid == 0){
			sum += left*base;
		}
		else if (mid == 1){
			sum += left*base + right + 1;
		}
		else{
			sum += (left + 1)*base;
		}
		base *= 10;
	}
	cout << sum;
	return 0;
}