#include <iostream>
#include <map>
#include <string>
using namespace::std;

int main(){
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	map<char, bool> strip;
	for (int i = 0; i < str2.size(); i++){
		strip[str2[i]] = true;
	}
	for (int i = 0; i < str1.size(); i++){
		if (strip[str1[i]])
			continue;
		cout << str1[i];
	}
	return 0;
}