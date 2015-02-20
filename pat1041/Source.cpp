#include <iostream>
#include <vector>
#include <map>
using namespace::std;

vector<int> nums;
map<int, int>bm;
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		auto it = bm.find(tmp);
		if (it != bm.end()){
			it->second++;
		}
		else{
			bm[tmp] = 1;
		}
		nums.push_back(tmp);
	}
	int winner = -1;;
	for (int i = 0; i < n; i++){
		if (bm[nums[i]] == 1){
			winner = nums[i];
			break;
		}
	}
	if (winner == -1){
		cout << "None";
	}
	else{
		cout << winner;
	}
	return 0;
}