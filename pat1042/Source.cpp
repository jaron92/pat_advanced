#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace::std;

int str2int(string str){
	return (str[0] - 'A') * 14 + atoi(str.substr(1).c_str());
}

string int2str(int v){
	char str[4];
	str[0] = v / 14 + 'A';
	sprintf(str + 1, "%d", v % 14);
	str[strlen(str)] = '\0';
	return string(str);
}

int main(){
	vector<int> origin, order, bm;
	bm.resize(54);
	string card[] = { string("S1"), string("H1"), string("C1"), string("D1"), string("J1") };
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 13; j++){
			origin.push_back(str2int(card[i]) + j);
		}
	}
	origin.push_back(str2int(card[4]));
	origin.push_back(str2int(card[4]) + 1);
	origin.push_back(-1);//из╠Ь
	int k;
	cin >> k;
	for (int i = 0; i < 54; i++){
		int po;
		cin >> po;
		order.push_back(po);
	}
	while (k--){
		bm.assign(54, 0);
		for (int i = 0; i < 54;i++){
			int j = i;
			origin[54] = origin[j];
			while (!bm[j]){
				bm[j] = 1;
				j = order[j] - 1;
				int tmp = origin[j];
				origin[j] = origin[54];
				origin[54] = tmp;
			}
		}
	}
	for (int i = 0; i < 53; i++){
		cout << int2str(origin[i]) << ' ';
	}
	cout << int2str(origin[53]) << endl;
	return 0;
}