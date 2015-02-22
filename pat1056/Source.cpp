#include <iostream>
#include <vector>
#include <queue>
using namespace::std;

int main(){
	int np, ng;
	cin >> np >> ng;
	vector<int> weight(np), rank(np, 0), counter_helper(np, 0);
	queue<int> group, order;
	for (int i = 0; i < np; i++){
		cin >> weight[i];
	}
	for (int i = 0; i < np; i++){
		int k;
		cin >> k; 
		order.push(k);
	}
	int counter = 0;
	while (order.size()!=1){
		queue<int> tmp;
		int gamecount = order.size() / ng + (order.size() % ng == 0 ? 0 : 1);
		int r = gamecount + 1;
		for (int i = 0; i < gamecount; i++){
			int max = -1, maxi;
			for (int j = 0; j < ng && !order.empty(); j++){
				if (weight[order.front()] > max){
					max = weight[order.front()];
					maxi = order.front();
				}
				rank[order.front()] = r;
				order.pop();
			}
			tmp.push(maxi);
		}
		order = tmp;
	}
	rank[order.front()] = 1;
	for (int i = 0; i < np - 1; i++){
		cout << rank[i] << ' ';
	}
	cout << rank[np - 1];
}