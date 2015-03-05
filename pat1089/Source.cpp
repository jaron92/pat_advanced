#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n), b, c(n);
	for (int i = 0; i < n; i++){
		cin >> c[i];
	}
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	b = c;
	bool flag = false;
	for (int i = 1; i < b.size(); i++){
		int po = i;
		for (int j = 0; j < i; j++){
			if (b[j]>b[i]){
				po = j;
				break;
			}
		}
		int tmp = b[i];
		for (int j = i - 1; j >= po; j--){
			b[j + 1] = b[j];
		}
		b[po] = tmp;
		if (b == a){
			cout << "Insertion Sort" << endl;
			flag = true;
			continue;
		}
		if (flag){
			for (int j = 0; j < b.size(); j++){
				cout << b[j];
				if (j != b.size() - 1)
					cout << ' ';
			}
			cout << endl;
			return 0;
		}
	}
	if (flag){
		for (int j = 0; j < b.size(); j++){
			cout << b[j];
			if (j != b.size() - 1)
				cout << ' ';
		}
		cout << endl;
		return 0;
	}
	b = c;
	for (int step = 1;;step*=2){
		for (int i = 0; i < b.size(); i += step){
			int ed = i + step <= b.size() ? i + step : b.size();
			sort(b.begin() + i, b.begin() + ed);
		}
		if (b == a){
			cout << "Merge Sort" << endl;
			flag = true;
			continue;
		}
		if (flag){
			for (int j = 0; j < b.size(); j++){
				cout << b[j];
				if (j != b.size() - 1)
					cout << ' ';
			}
			cout << endl;
			return 0;
		}
	}
	if (flag){
		for (int j = 0; j < b.size(); j++){
			cout << b[j];
			if (j != b.size() - 1)
				cout << ' ';
		}
		cout << endl;
		return 0;
	}
}