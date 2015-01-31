#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace::std;

bool isPalindromic(char str[]){
	int i;
	for (i = 0; i < strlen(str) / 2; i++){
		if (str[strlen(str) - 1 - i] != str[i])
			break;
	}
	if (i == strlen(str) / 2)
		return true;
	else
		return false;
}

int main(){
	char in[200], reverse[200], out[200];
	int k, carry=0, m;
	cin >> in >> k;
	m = k;
	while (m--){
		if (isPalindromic(in))
			break;
		carry = 0;
		for (int i = strlen(in) - 1; i >= 0; i--)
			reverse[strlen(in) - 1 - i] = in[i];
		for (int i = strlen(in) - 1; i >= 0; i--){
			out[strlen(in) - 1 - i] = (in[i] - '0' + reverse[i] - '0' + carry) % 10 + '0';
			carry = (in[i] - '0' + reverse[i] - '0' + carry) / 10;
		}
		if (carry != 0){
			out[strlen(in)] = carry + '0';
			out[strlen(in) + 1] = '\0';
		}
		else {
			out[strlen(in)] = '\0';
		}
		for (int i = 0; i < strlen(out) / 2; i++){
			int tmp = out[strlen(out) - i - 1];
			out[strlen(out) - i - 1] = out[i];
			out[i] = tmp;
		}
		strcpy(in, out);
	}
	cout << in << endl;
	cout << k - m - 1;
	return 0;
}