#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <iomanip>

using namespace::std;

int process_time[1001], queries[1001], finish_time[1001];
vector<queue<int> > line;

int min_m(int n){
	int min = INT_MAX, j;
	for (int i = 0; i < n; i++){
		int front = line[i].front();
		if (front < min){
			min = front;
			j = i;
		}
	}
	return j;
}

int main(){
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	line.resize(n);
	
	for (int i = 0; i < k; i++){
		cin >> process_time[i];
	}
	for (int i = 0; i < q; i++){
		cin >> queries[i];
	}
	for (int i = 0; i < k; i++){
		if (i < m*n){
			if (i<n)
				finish_time[i] = process_time[i];
			else
				finish_time[i] = finish_time[i - n] + process_time[i];
			line[i%n].push(finish_time[i]);
			continue;
		}
		int avail = min_m(n);
		finish_time[i] = line[avail].back() + process_time[i];
		line[avail].pop();
		line[avail].push(finish_time[i]);
	}
	for (int j = 0; j < q; j++){
		int h, m, sh, sm;
		int i = queries[j] - 1;
		sh = (finish_time[i] - process_time[i]) / 60 + 8;
		h = finish_time[i] / 60 + 8;
		m = finish_time[i] % 60;
		if (sh >= 17){
			cout << "Sorry" << endl;
			continue;
		}
		cout.fill('0');
		cout << setw(2) << h << ':' << setw(2) << m << endl;
	}
	return 0;
}