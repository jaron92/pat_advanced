#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace::std;

inline int name2id(char* name){
	return (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + (name[3] - '0');
}

unordered_map<int, vector<int>> stu;
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++){
		int index, ni;
		scanf("%d%d", &index, &ni);
		for (int j = 0; j < ni; j++){
			char name[5];
			scanf("%s", name);
			stu[name2id(name)].push_back(index);
		}
	}
	for (int i = 0; i < n; i++){
		char name[5];
		scanf("%s", name);
		auto it = stu.find(name2id(name));
		cout << name << ' ';
		if (it == stu.end()){
			cout << 0 << endl;
			continue;
		}
		sort(it->second.begin(), it->second.end());
		printf("%d ", it->second.size());
		for (auto iter = it->second.begin(); iter != it->second.end() - 1; iter++){
			printf("%d ", *iter);
		}
		printf("%d\n", *(it->second.end() - 1));
	}
	return 0;
}