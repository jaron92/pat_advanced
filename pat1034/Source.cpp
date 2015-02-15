#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
using namespace::std;

map<string, int> str2num;
map<int, string> num2str;
vector<int> callersum, gangsum, sum, pre, bm, boss, visited, head;

int Find(int num){
	int r = num;
	while (pre[r]!=-1){
		r = pre[r];
	}
	return r;
}


void Join(int a, int b){
	int fa = Find(a), fb = Find(b);
	if (fa!=fb){
		pre[fa] = fb;
	}
}

bool compare(int a, int b){
	return num2str[a] < num2str[b];
}

int main(){
	int n, k;
	cin >> n >> k;
	callersum.resize(2*n, 0);
	sum.resize(2*n, 0);
	pre.resize(2*n, -1);
	int num1, num2, num = 0;
	for (int i = 0; i < n; i++){
		string name1, name2;
		int time;
		cin >> name1 >> name2;
		if (str2num.find(name1) == str2num.end()){
			num1 = num;
			str2num[name1] = num1;
			num2str[num1] = name1;
			num++;
		}
		else {
			num1 = str2num[name1];
		}
		if (str2num.find(name2) == str2num.end()){
			num2 = num;
			str2num[name2] = num2;
			num2str[num2] = name2;
			num++;
		}
		else{
			num2 = str2num[name2];
		}
		cin >> time;
		callersum[num1] += time;
		sum[num1] += time;
		sum[num2] += time;
		Join(num1, num2);
	}
	visited.resize(num, 0);
	bm.resize(num, 0);
	gangsum.resize(num, 0);
	boss.resize(num, -1);
	for (int i = 0; i < num; i++){
		boss[i] = Find(i);
		bm[Find(i)] += 1;
		gangsum[Find(i)] += callersum[i];
	}

	int counter = 0, max, maxi;
	for (int i = 0; i < num; i++){
		if (gangsum[i]>k && bm[i] > 2){
			max = INT_MIN;
			for (int j = 0; j < num; j++){
				if (visited[j])
					continue;
				if (boss[j] == i&&sum[j] > max){
					max = sum[j];
					maxi = j;
					visited[j] = 1;
				}
			}
			head.push_back(maxi);
			counter++;
		}
			
	}
	sort(head.begin(), head.end(), compare);
	cout << counter << endl;
	for (auto it = head.begin(); it != head.end(); it++){
		cout << num2str[*it] << ' ' << bm[boss[*it]] << endl;
	}
}