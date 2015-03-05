#include <iostream>
#include <vector>
#include <iomanip>
using namespace::std;

typedef struct Node
{
	double p;
	vector<int> child;
}Node;

vector<Node> chain;

void cal(int i, double p, double r){
	chain[i].p = p;
	for (int j = 0; j < chain[i].child.size(); j++){
		cal(chain[i].child[j], p*(1 + r / 100), r);
	}
}

int main(){
	int n;
	double p, r;
	cin >> n >> p >> r;
	chain.resize(n);
	Node st;
	for (int i = 0; i < n; i++){
		int fa;
		cin >> fa;
		if (fa != -1){
			chain[fa].child.push_back(i);
		}
		else{
			st.child.push_back(i);
		}
	}
	st.p = p;
	for (int i = 0; i < st.child.size(); i++){
		cal(st.child[i], p, r);
	}
	double max = -1;
	int counter = 0;
	for (int i = 0; i < chain.size(); i++){
		if (chain[i].p > max){
			max = chain[i].p;
			counter = 1;
		}
		else if (max == chain[i].p) {
			counter++;
		}
	}
	cout.setf(ios::fixed);
	cout << setprecision(2) << max << ' ' << counter << endl;
	return 0;
}