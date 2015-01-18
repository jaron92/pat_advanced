#include <iostream>

using namespace::std;

int main(){
	int n, floor, sum = 0, pre = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> floor;
		if (floor>pre)
			sum += 6 * (floor - pre);
		else
			sum += 4 * (pre - floor);
		sum += 5;
		pre = floor;
	}
	cout << sum;
	return 0;
}