#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

typedef vector<int> node;

vector<int> weight, path;
vector<node> tree;
vector<vector<int>> result;
void dfs(int id, int sum, int s){
	path.push_back(weight[id]);
	sum += weight[id];
	if (sum == s && tree[id].empty()){
		result.push_back(path);
	}
	for (int i = 0; i < tree[id].size(); i++){
		dfs(tree[id][i], sum, s);
	}
	path.pop_back();
}

bool compare(vector<int> a, vector<int> b){
	int len = a.size() > b.size() ? b.size() : a.size();
	for (int i = 0; i < len; i++){
		if (a[i] == b[i] && i < len - 1)
			continue;
		return a[i] > b[i];
	}
}

int main(){
	int n, m, s;
	cin >> n >> m >> s;
	weight.resize(n);
	tree.resize(n);
	for (int i = 0; i < n; i++){
		cin >> weight[i];
	}
	for (int i = 0; i < m; i++){
		int id, num;
		cin >> id>>num;
		tree[id].resize(num);
		for (int j = 0; j < num; j++){
			cin >> tree[id][j];
		}
	}
	dfs(0, 0, s);
	sort(result.begin(), result.end(), compare);
	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[i].size() - 1; j++){
			cout << result[i][j] << ' ';
		}
		cout << result[i][result[i].size() - 1] << endl;
	}
	return 0;
}