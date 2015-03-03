#include <iostream>
#include <iomanip>
#include <vector>
using namespace::std;

typedef struct Node
{
	double p;
	vector<int> child;
}Node;

vector<Node> chain;

void setp(int st, double p, double r){
	for (int i = 0; i<chain[st].child.size(); i++){
		chain[chain[st].child[i]].p = chain[st].p*(1 + r / 100);
		setp(chain[st].child[i], p, r);
	}
}

int main(){
	int n;
	double p, r;
	cin >> n >> p >> r;
	chain.resize(n);
	vector<int> amount(n, -1);
	chain[0].p = p;
	for (int i = 0; i < n; i++){
		int k;
		cin >> k;
		if (k == 0){
			cin >> amount[i];
			continue;
		}
		for (int j = 0; j < k; j++){
			int v;
			cin >> v;
			chain[i].child.push_back(v);
		}
	}
	setp(0, p, r);
	double sum = 0;
	for (int i = 0; i < n; i++){
		if (amount[i] != -1){
			sum += amount[i] * chain[i].p;
		}
	}
	cout.setf(ios::fixed);
	cout << setprecision(1) <<sum << endl;
	return 0;
}