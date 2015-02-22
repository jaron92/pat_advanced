#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace::std;

int str2id(char name[]){
	return (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + (name[3] - '0');
}

string id2str(int id){
	char str[5];
	str[4] = '\0';
	str[3] = id % 10 + '0';
	str[2] = id % (26 * 10) / 10 + 'A';
	str[1] = id % (26 * 26 * 10) / (26 * 10) + 'A';
	str[0] = id / (26 * 26 * 10) + 'A';
	return string(str);
}

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	vector<vector<int>> course(k+1);	
	for (int i = 0; i < n; i++){
		char name[5];
		scanf("%s", name);
		int id = str2id(name);
		int c;
		cin >> c;
		for (int j = 0; j < c; j++){
			int index;
			scanf("%d", &index);
			course[index].push_back(id);
		}
	}
	for (int i = 1; i <= k; i++){
		//cout << i << ' ' << course[i].size() << endl;
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end());
		for (auto it = course[i].begin(); it != course[i].end(); it++)
			//cout << id2str(*it) << endl;
			printf("%s\n", id2str(*it).c_str());
	}
	return 0;
}