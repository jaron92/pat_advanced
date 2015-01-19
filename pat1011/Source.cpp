#include <iostream>
#include <iomanip>

using namespace::std;

int max3(float a[]){
	int maxi;
	float max = 0;
	for (int i = 0; i < 3; i++){
		if (a[i]>max){
			max = a[i];
			maxi = i;
		}
	}
	return maxi;
}

int main(){
	char t[3] = { 'W', 'T', 'L' };
	float sum = 0, coe = 1;
	for (int i = 0; i < 3; i++){
		float a[3];
		int maxi;
		cin >> a[0] >> a[1] >> a[2];
		maxi = max3(a);
		coe *= a[maxi];
		cout << t[maxi] << ' ';
	}
	cout.setf(ios::fixed);
	cout << setprecision(2) << (coe*0.65 - 1) * 2;
	return 0;
}