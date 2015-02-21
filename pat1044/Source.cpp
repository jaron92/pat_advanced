#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
using namespace::std;

int main(){
	int n, m;
	//cin >> n >> m;
	scanf("%d%d", &n, &m);
	vector<int> diamond(n + 1);
	vector<pair<int, int>> solutions;
	diamond[0] = 0;
	for (int i = 1; i <= n; i++){
		//cin >> diamond[i];
		scanf("%d", &diamond[i]);
		diamond[i] += diamond[i - 1];
	}
	int min = INT_MAX;
	for (int i = 1; i <= n; i++){
		int r = n, l = i, pre;
		while (r > l){
			int mid = (l + r) / 2;
			if (diamond[mid] - diamond[i - 1] >= m){
				r = mid;
			}
			else if (diamond[mid] - diamond[i - 1] < m){
				l = mid + 1;
			}
		}
		if (diamond[r] - diamond[i - 1] < m){
			continue;
		}
		if (diamond[r] - diamond[i - 1] < min){
			min = diamond[r] - diamond[i - 1];
			solutions.clear();
			solutions.push_back(make_pair(i, r));
		}
		else if (diamond[r] - diamond[i - 1] == min){
			solutions.push_back(make_pair(i, r));
		}
	}
	for (auto it = solutions.begin(); it != solutions.end(); it++){
		//cout << it->first << '-' << it->second << endl;
		printf("%d-%d\n", it->first, it->second);
	}
	return 0;
}