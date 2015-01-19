//虽然一次性ac，但是实现过于繁琐
#include <iostream>
#include <climits>

using namespace::std;

int id[2000], c[2000], m[2000], e[2000], a[2000], cr[2000], mr[2000] = { 0 }, er[2000] = { 0 }, ar[2000] = { 0 }, id2index[1000000];
int sub;

int min3(int a, int b, int c, int d){
	int min = INT_MAX;
	if (d < min){
		min = d;
		sub = 3;
	}
	if (a < min){
		min = a;
		sub = 0;
	}
	if (b < min){
		min = b;
		sub = 1;
	}
	if (c < min){
		min = c;
		sub = 2;
	}

	return min;
}

int main(){
	int n, k;
	char subject[4] = { 'C', 'M', 'E', 'A' };
	for (int i = 0; i < 1000000; i++){
		id2index[i] = -1;
	}
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> id[i] >> c[i] >> m[i] >> e[i];
		a[i] = (c[i] + m[i] + e[i]) / 3;
		id2index[id[i]] = i;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (c[j]>c[i])
				cr[i]++;
			if (m[j]>m[i])
				mr[i]++;
			if (e[j]>e[i])
				er[i]++;
			if (a[j]>a[i])
				ar[i]++;
		}
	}
	for (int i = 0; i < k; i++){
		int id, index;
		cin >> id;
		index = id2index[id];
		if (index == -1){
			cout << "N/A" << endl;
			continue;
		}
		cout << min3(cr[index], mr[index], er[index], ar[index]) + 1 << ' ';
		cout<< subject[sub] << endl;
	}
	
	return 0;
}