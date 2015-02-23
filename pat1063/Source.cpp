#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <cstdio>
#include <set>
#include <algorithm>
#include <iterator>
using namespace::std;

vector<set<int> > data;

float caculateSim(int s1, int s2){
	set<int> com, sum;
	set_intersection(data[s1].begin(), data[s1].end(), data[s2].begin(), data[s2].end(), inserter(com, com.begin()));

	return com.size()*1.0 / (data[s1].size() + data[s2].size() - com.size());
}

int main(){
	int n;
	//cin >> n;
	scanf("%d", &n);
	data.resize(n);
	for (int i = 0; i < n; i++){
		int m;
		//cin >> m;
		scanf("%d", &m);
		for (int j = 0; j < m; j++){
			int v;
			//cin >> v;
			scanf("%d", &v);
			data[i].insert(v);
		}
	}
	int k;
	//cin >> k;
	scanf("%d", &k);
	//cout.setf(ios::fixed);
	for (int i = 0; i < k; i++){
		int s1, s2;
		//cin >> s1 >> s2;
		scanf("%d%d", &s1, &s2);
		//cout << setprecision(1) << caculateSim(s1 - 1, s2 - 1) * 100 << '%' << endl;
		printf("%.1f%%\n", caculateSim(s1 - 1, s2 - 1) * 100);
	}
	return 0;
}
