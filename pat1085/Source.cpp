#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

typedef long long ll;

int main(){
	ll n, p;
	cin >> n >> p;
	vector<ll> seq(n);
	for (int i = 0; i < n; i++){
		cin >> seq[i];
	}
	sort(seq.begin(), seq.end());
	int max = 1;
	for (int i = 0; i < seq.size(); i++){
		for (int j = i + max; j < seq.size(); j++){
			if (seq[j]>seq[i] * p)
				break;
			if (j - i + 1 > max)
				max = j - i + 1;
		}
	}
	cout << max;
}