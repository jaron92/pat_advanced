#include <iostream>
using namespace::std;

int main(){
	unsigned long int n, b, m, a[64];
	int counter = 0;
	cin >> n >> b;
	m = n;
	if (m == 0){
		cout << "Yes" << endl << '0';
		return 0;
	}
	while (m != 0){
		a[counter++] = m%b;
		m /= b;
	}
	int i;
	for (i = 0; i < counter / 2; i++){
		if (a[i] != a[counter - 1 - i])
			break;
	}
	if (i == counter / 2)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int j = counter - 1; j > 0; j--)
		cout << a[j] << ' ';
	cout << a[0];
	return 0;
}