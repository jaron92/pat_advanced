#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace::std;

typedef struct testee
{
	string num;
	int mark;
	int localrank;
	int localnum;
	int finalrank;
}testee;

vector<vector<testee> > testlist;
vector<testee> sumlist;

bool compare(testee a, testee b){
	if (a.mark == b.mark)
		return a.num < b.num;
	return a.mark > b.mark;
}

int main(){
	int n, counter, min = 101, sum = 0, mini;
	cin >> n;
	testlist.resize(n);
	for (int i = 0; i < n; i++){
		int k;
		cin >> k;
		sum += k;
		for (int j = 0; j < k; j++){
			testee *t = new testee;
			cin >> t->num;
			cin >> t->mark;
			t->localnum = i + 1;
			testlist[i].push_back(*t);
			delete t;
		}
		sort(testlist[i].begin(), testlist[i].end(), compare);
		counter = 1;
		min = INT_MAX;
		for (vector<testee>::iterator it = testlist[i].begin(); it != testlist[i].end(); it++){
			if (it->mark < min){
				min = it->mark;
				it->localrank = counter;
				mini = counter;
			}
			else if (it->mark == min){
				it->localrank = mini;
			}
			counter++;
			sumlist.push_back(*it);
		}
	}
	sort(sumlist.begin(), sumlist.end(), compare);
	counter = 1;
	min = INT_MAX;
	for (vector<testee>::iterator it = sumlist.begin(); it != sumlist.end(); it++){
		if (it->mark < min){
			min = it->mark;
			it->finalrank = counter;
			mini = counter;
		}
		else if (it->mark == min){
			it->finalrank = mini;
		}
		counter++;
	}
	cout << sum << endl;
	for (vector<testee>::iterator it = sumlist.begin(); it != sumlist.end(); it++){
		cout << it->num << ' ' << it->finalrank << ' ' << it->localnum << ' ' << it->localrank << endl;
	}
	return 0;
}
