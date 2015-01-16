#include <iostream>
#include <iomanip>

using namespace::std;

int main(){
	int k, ep, co;
	float c1[1001] = { 0 }, c2[1001] = { 0 };
	for (int j = 0; j < 2; j++){
		cin >> k;
		for (int i = 0; i < k; i++){
			cin >> ep;
			if (j == 0)
				cin >> c1[ep];
			if (j == 1)
				cin >> c2[ep];
		}
	}
	
	int count = 0;
	for (int i = 0; i < 1001; i++){
		c1[i] += c2[i];
		if (c1[i] != 0)
			count++;
	}
	
	cout << count;
	cout.setf(ios::fixed);
	for (int i = 1000; i >= 0; i--)
		if (c1[i] != 0)
			cout << ' ' << i << ' ' << setprecision(1) << c1[i];
	
}