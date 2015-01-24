#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iomanip>

using namespace::std;

typedef struct queuetime
{
	int arrivetime;
	int waitingtime;
	int processtime;
	int finishtime;
}queuetime;

vector<queuetime> qtime;
vector<queuetime> window;

int fast(int k){
	int min = INT_MAX, mini;
	for (int i = 0; i < k; i++){
		if (window[i].finishtime < min){
			min = window[i].finishtime;
			mini = i;
		}
	}
	return mini;
}

bool compare(queuetime a, queuetime b){
	return a.arrivetime < b.arrivetime;
}

int main(){
	int n, k, sum, count = 0;
	cin >> n >> k;
	qtime.resize(n);
	window.resize(k);
	queuetime *tmp;
	for (int i = 0; i < n; i++){
		string time;
		cin >> time;
		int h, m, s, sum;
		h = atoi(time.substr(0, 2).c_str());
		m = atoi(time.substr(3, 5).c_str());
		s = atoi(time.substr(6, 8).c_str());
		sum = h * 60 * 60 + m * 60 + s;//统一为秒
		cin >> m;
		if (sum > 17 * 60 * 60)
			continue;
		tmp = new queuetime;
		tmp->arrivetime = sum;
		tmp->processtime = m > 60 ? 60 * 60 : m * 60;
		qtime[count++] = *tmp;
	}
	qtime.resize(count);//排除晚于五点的值
	sort(qtime.begin(), qtime.end(), compare);
	sum = 0;
	cout.setf(ios::fixed);
	for (int i = 0; i < count; i++){
		if (i < k){
			int wt;
			wt = (8 * 60 * 60) - qtime[i].arrivetime;
			qtime[i].waitingtime = wt < 0 ? 0 : wt;
			qtime[i].finishtime = qtime[i].arrivetime + qtime[i].waitingtime + qtime[i].processtime;
			window[i%k] = qtime[i];
		}
		else {
			int index = fast(k);
			int wt;
			wt = window[index].finishtime - qtime[i].arrivetime;
			qtime[i].waitingtime = wt < 0 ? 0 : wt;
			qtime[i].finishtime = qtime[i].arrivetime + qtime[i].waitingtime + qtime[i].processtime;
			window[index] = qtime[i];
		}
		sum += qtime[i].waitingtime;
	}
	cout <<setprecision(1) << sum*1.0 / (60 * count);
	return 0;
}