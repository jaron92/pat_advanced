#include <iostream>
#include <iomanip>

using namespace::std;

int main(){
	int a, b;
	cin >> a >> b;
	int c = a + b;
	int d[10] = { 0 };
	int flag = 0;
	if (c < 0){
		flag = 1;
	}
	int i = 0;
	while (abs(c) != 0){
		d[i++] = abs(c) % 1000;
		c = abs(c) / 1000;
	}
	if (flag)
		cout << '-';
	cout.fill('0');
	for (int j = i - 1; j > 0; j--){
		if (j==i-1)
			cout << d[j] << ',';
		else
			cout << setw(3) << d[j] << ',';
	}
	if (i > 1)
		cout << setw(3) << d[0];
	else
		cout << d[0];
	return 0;
}