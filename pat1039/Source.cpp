#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace::std;

map<string, vector<int>> stu;
int main(){
	int n, k;
	//cin >> n >> k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++){
		int index, ni;
		//cin >> index >> ni;
		scanf("%d%d", &index, &ni);
		for (int j = 0; j < ni; j++){
			char str[10];
			scanf("%s", str);
			stu[string(str)].push_back(index);
		}
	}
	for (int i = 0; i < n; i++){
		string name;
		cin >> name;
		auto it = stu.find(name);
		cout << name << ' ';
		if (it == stu.end()){
			cout << 0 << endl;
			continue;
		}
		sort(it->second.begin(), it->second.end());
		//cout << it->second.size() << ' ';
		printf("%d ", it->second.size());
		for (auto iter = it->second.begin(); iter != it->second.end()-1; iter++){
			//cout << *iter << ' ';
			printf("%d ", *iter);
		}
		//cout << *(it->second.end() - 1) << endl;
		printf("%d\n", *(it->second.end() - 1));
	}
}