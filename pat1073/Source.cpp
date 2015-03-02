#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace::std;

int main(){
	string sci;
	cin >> sci;
	if (sci[0] == '-')
		cout << sci[0];
	int dpos = sci.find('.');
	int epos = sci.find('E');
	int ex = atoi(sci.substr(epos + 1).c_str());
	int declen = epos - dpos - 1;
	vector<char> conv;
	if (ex < 0){
		conv.resize(-ex - 1, '0');
		for (int i = 1; i < epos; i++){
			if (sci[i] != '.')
				conv.push_back(sci[i]);
		}
		cout << "0.";
		for (int i = 0; i < conv.size(); i++)
			cout << conv[i];
	}
	else{
		int add = ex>declen ? ex - declen : 0;
		for (int i = 1; i < epos; i++){
			if (sci[i] != '.')
				conv.push_back(sci[i]);
		}
		for (int i = 0; i < add; i++){
			conv.push_back('0');
		}
		for (int i = 0; i < conv.size(); i++){
			if (i == ex + 1)
				cout << '.';
			cout << conv[i];
		}
	}
	return 0;
}