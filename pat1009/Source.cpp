//糟糕的实现，有待优化……
#include <iostream>
#include <iomanip>

using namespace::std;

//int ex1[1001],  ex2[1001];
float coe1[1001] = { 0 }, coe2[1001] = { 0 }, coe3[2001] = { 0 };

int main(){
	int k1, k2;
	cin >> k1;
	for (int i = 0; i < k1; i++){
		int ex;
		cin >> ex;
		cin >> coe1[ex];
	}
	cin >> k2;
	for (int i = 0; i < k2; i++){
		int ex;
		cin >> ex;
		cin >> coe2[ex];
	}
	for (int i = 0; i < 1001; i++){
		for (int j = 0; j < 1001; j++){
			coe3[i + j] += coe1[i] * coe2[j];
		}
	}
	int count = 0;
	for (int i = 0; i < 2001; i++){
		if (coe3[i] != 0)
			count++;
	}
	cout << count;
	cout.setf(ios::fixed);
	for (int i = 2000; i >=0; i--){
		if (coe3[i] != 0){
			cout << ' ' << i << ' '<<setprecision(1) << coe3[i];
		}
	}
}