#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace::std;


int main(){
	int n1, n2;
	vector<long> nc, np;
	cin >> n1;
	for (int i = 0; i < n1; i++){
		long v;
		cin >> v;
		nc.push_back(v);
	}
	cin >> n2;
	for (int i = 0; i < n2; i++){
		long v;
		cin >> v;
		np.push_back(v);
	}
	sort(nc.begin(), nc.end());
	sort(np.begin(), np.end());
	int j = 0, k = 0;
	long sum = 0;
	while (nc[j] < 0 && np[k] < 0 && j < n1 && k < n2){
		sum += nc[j] * np[k];
		j++;
		k++;
	}
	j = n1 - 1;
	k = n2 - 1;
	while (nc[j] > 0 && np[k] > 0 && j >= 0 && k >= 0){
		sum += nc[j] * np[k];
		j--;
		k--;
	}
	cout << sum;
	return 0;
}