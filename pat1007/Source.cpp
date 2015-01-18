#include <iostream>

using namespace::std;

int a[10000], first[10000], sum[10000] = { 0 };

int main(){
	int n, s=0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	first[0] = 0;
	sum[0] = a[0];
	for (int i = 1; i < n; i++){
		if (sum[i - 1] >= 0){
			sum[i] = a[i] + sum[i-1];
			first[i] = first[i - 1];
		}
		else{
			sum[i] = a[i];
			first[i] = i;
		}
	}
	int max = -1, maxi;
	for (int i = 0; i < n; i++){
		if (sum[i]>max){
			max = sum[i];
			maxi = i;
		}
	}
	if (max==-1)
		cout << "0 " << a[0] << ' ' << a[n - 1];
	else
		cout << max << ' ' << a[first[maxi]] << ' ' << a[maxi];
}