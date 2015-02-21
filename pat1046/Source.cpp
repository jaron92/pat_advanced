#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
using namespace::std;

int main(){
	int n, sum = 0;
	scanf("%d", &n);
	vector<int> distan(n+1), distanSum(n+1);
	distanSum[0] = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", &distan[i]);
		sum += distan[i];
		distanSum[i] = distanSum[i - 1] + distan[i];
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		int start, end;
		scanf("%d%d", &start, &end);
		if (start > end){
			int tmp = start;
			start = end;
			end = tmp;
		}
		int sum1 = distanSum[end-1] - distanSum[start - 1];
		if (sum1 < sum-sum1)
			printf("%d\n", sum1);
		else
			printf("%d\n", sum-sum1);
	}
	return 0;
}