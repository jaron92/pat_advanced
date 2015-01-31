#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace::std;

bool compare(char a, char b){
	return a > b;
}

int main(){
	char ori[21], dou[22], tmp[22];
	cin >> ori;
	int carry = 0, counter = 0;
	for (int i = strlen(ori) - 1; i >= 0; i--){
		dou[counter++] = ((ori[i] - '0') * 2 + carry) % 10 + '0';
		carry = ((ori[i] - '0') * 2 + carry) / 10;
	}
	if (carry != 0)
		dou[counter++] = carry + '0';
	dou[counter] = '\0';
	strcpy(tmp, dou);
	sort(ori, ori + strlen(ori), compare);
	sort(dou, dou + counter, compare);
	if (strcmp(ori, dou) != 0)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	for (int i = counter - 1; i >= 0; i--)
		cout << tmp[i];
}