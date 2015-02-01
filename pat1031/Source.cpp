#include <iostream>
#include <deque>
#include <string>
#include <climits>
using namespace::std;

int main(){
	string str;
	deque<char> qu;
	cin >> str;
	for (int i = 0; i < str.length(); i++){
		qu.push_back(str[i]);
	}
	int n1, n2, n3, max=INT_MIN;
	for (int i = str.length(); i >= 3; i--){
		for (int j = i; j > 0; j--){
			if (i + j + j - 2 == str.length()){
				if (j > max)
					max = j;
			}
		}
	}
	n1 = n3 = max;
	n2 = str.length() + 2 - n1 - n3;
	for (int i = 0; i < n1-1; i++){
		cout << qu.front();
		for (int j = 0; j < n2 - 2; j++)
			cout << ' ';
		cout << qu.back() << endl;
		qu.pop_back();
		qu.pop_front();
		
	}
	while (!qu.empty()){
		cout << qu.front();
		qu.pop_front();
	}
	return 0;
}