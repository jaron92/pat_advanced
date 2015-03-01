#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace::std;

vector<int> a, bp;

int nextp(int start){
	int i;
	static int ne = 1;
	if (start == 0){
		for (i = ne; i < a.size(); i++){
			if (a[i] != i){
				ne = i;
				return i;
			}
		}
		if (i == a.size())
			return -1;
	}
	return bp[start];
}

void swap(int i, int j){
	bp[a[i]] = j;
	bp[a[j]] = i;
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;

}

int main(){
	int n, start;
	//cin >> n;
	scanf("%d", &n);
	a.resize(n);
	bp.resize(n);
	for (int i = 0; i < n; i++){
		//cin >> a[i];
		scanf("%d", &a[i]);
		bp[a[i]] = i;
		if (a[i] == 0)
			start = i;
	}
	int counter = 0;
	while (1){
		int po = nextp(start);
		if (po == -1)
			break;
		//cout << "po:" << po << endl;
		swap(po, start);
		start = po;
		counter++;
	}
	//cout << counter << endl;
	printf("%d\n", counter);
}