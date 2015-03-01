#include <iostream>
#include <algorithm>
#include <vector>
using namespace::std;

vector<int> nodes, tree;
int pos = 0, n;
void build(int root){
	if (root > n){
		return;
	}
	int l = root * 2, r = root * 2 + 1;
	build(l);
	tree[root] = nodes[pos++];
	build(r);
}

int main(){
	cin >> n;
	nodes.resize(n);
	tree.resize(n+1);
	for (int i = 0; i < n; i++){
		cin >> nodes[i];
	}
	sort(nodes.begin(), nodes.end());
	build(1);
	for (int i = 1; i <= n - 1; i++){
		cout << tree[i] << ' ';
	}
	cout << tree[n];
	return 0;
}