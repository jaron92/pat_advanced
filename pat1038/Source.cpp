#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace::std;

bool compare(string a, string b){
	return a + b < b + a;
}

int main(){
	vector<string> numbers;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string str;
		cin >> str;
		numbers.push_back(str);
	}
	sort(numbers.begin(), numbers.end(), compare);
	string sum;
	for (int i = 0; i < n; i++){
		sum += numbers[i];
	}
	int k = 0;
	while (sum[k] == '0'){
		k++;
	}
	if (k == sum.length()){
		cout << '0';
	}
	else{
		cout << sum.substr(k);
	}
	return 0;
}