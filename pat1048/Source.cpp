#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace::std;

inline int min(int a, int b){
	if (a < b)
		return a;
	else
		return b;
}

bool compare(pair<int, int> a, pair<int, int> b){
	return a.first < b.first;
}

vector<pair<int, int>> SumToK(const vector<int>& nums, int k){
	vector<pair<int, int>> result;
	map<int, bool> pre;
	pre[nums[0]] = true;
	for (int i = 1; i < nums.size(); i++){
		auto it = pre.find(k - nums[i]);
		if (it != pre.end()){
			if (it->first){//find it!
				result.push_back(make_pair(min(nums[i], k - nums[i]), k - min(nums[i], k - nums[i])));
				it->second = false;
				pre[nums[i]] = false;
			}
		}
		else{
			pre[nums[i]] = true;
		}
	}
	return result;
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	for (int i = 0; i < n; i++){
		cin >> nums[i];
	}
	auto result = SumToK(nums, k);
	sort(result.begin(), result.end(), compare);
	if (result.size() == 0){
		cout << "No Solution" << endl;
	}
	else{
		cout << result[0].first << ' ' << result[0].second << endl;
	}
	return 0;
}