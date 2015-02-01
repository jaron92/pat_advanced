#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>
using namespace::std;

int main(){
	vector<int> seq1, seq2;
	int n, m, data, mid;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &data);
		seq1.push_back(data);
	}
	seq1.push_back(INT_MAX);
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		scanf("%d", &data);
		seq2.push_back(data);
	}
	seq2.push_back(INT_MAX);
	mid = (m + n - 1) / 2;
	int counter = 0, value;
	vector<int>::iterator it1 = seq1.begin(), it2 = seq2.begin(), it;
	while (counter<mid){
		if (*it1 > *it2){
			it2++;
		}
		else{
			value = *it1;
			it1++;
		}
		counter++;
	}
	it = *it1>*it2 ? it2 : it1;
	printf("%d\n", *it);
}
