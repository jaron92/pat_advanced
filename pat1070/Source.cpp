#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
using namespace::std;

bool compare(double a, double b){
	return a > b;
}

int main(){
	int n, d;
	cin >> n >> d;
	vector<double> amounts(n), prices(n), avgs(n);
	map<double, int> mp;
	for (int i = 0; i < n; i++){
		cin >> amounts[i];
	}
	for (int i = 0; i < n; i++){
		cin >> prices[i];
		avgs[i] = prices[i] / amounts[i];
		mp[avgs[i]] = i;
	}
	sort(avgs.begin(), avgs.end(), compare);
	cout.setf(ios::fixed);
	double total = 0;
	for (int i = 0; i < avgs.size(); i++){
		if (amounts[mp[avgs[i]]] <= d){
			total += prices[mp[avgs[i]]];
			d -= amounts[mp[avgs[i]]];
		}
		else{
			total += prices[mp[avgs[i]]] * d / amounts[mp[avgs[i]]];
			d = 0;
		}
		if (d == 0)
			break;
	}
	cout << setprecision(2) << total << endl;
}