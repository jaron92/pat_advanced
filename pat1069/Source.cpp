#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace::std;

int nums2int(vector<int>& nums){
	int start;
	for (int i = 0; i < nums.size(); i++){
		if (nums[i] != 0){
			start = i;
			break;
		}
	}
	int rst = 0, c = 1;
	for (int i = nums.size() - 1; i >= start; i--){
		rst += c*nums[i];
		c *= 10;
	}
	return rst;
}

bool compare(int a, int b){
	return a > b;
}

int main(){
	int n;
	cin >> n;
	vector<int> numsl, numsb;
	cout.fill('0');
	while (true){
		numsl.clear();
		while (numsl.size()!=4){
				numsl.push_back(n % 10);
				n /= 10;
			}
		numsb = numsl;
		sort(numsl.begin(), numsl.end());
		sort(numsb.begin(), numsb.end(), compare);
		int m, s;
		m = nums2int(numsl);
		s = nums2int(numsb);
		n = s - m;
		cout << setw(4) << s << " - " << setw(4) << m << " = " << setw(4) << n << endl;
		if (n == 6174 || n == 0)
			break;
	}
	return 0;
}