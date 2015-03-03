#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace::std;

int main(){
	int n, l;
	cin >> n >> l;
	vector<vector<int> > follows(n + 1);
	for (int i = 1; i <= n; i++){
		int m;
		cin >> m;
		for (int j = 0; j < m; j++){
			int id;
			cin >> id;
			follows[id].push_back(i);
		}
	}
	int k;
	cin >> k;
	queue<int> rst, tmpq;
	unordered_map<int, int> mp;
	for (int i = 0; i < k; i++){
		int q;
		cin >> q;
		int tmp = l;
		mp.clear();
		while (!rst.empty())
			rst.pop();
		rst.push(q);
		mp[q] = 1;
		while (true){
			while (!rst.empty()){
				for (int j = 0; j < follows[rst.front()].size(); j++){
					int id = follows[rst.front()][j];
					auto it = mp.find(id);
					if (it == mp.end()){
						tmpq.push(id);
						mp[id] = 1;
					}	
				}
				rst.pop();
			}
			rst = tmpq;
			while (!tmpq.empty())
				tmpq.pop();
			if (tmp-- == 1){
				cout << mp.size() - 1 << endl;
				break;
			}
		}
	}
	return 0;
}