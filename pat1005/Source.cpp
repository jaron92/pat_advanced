#include <iostream>
#include <cstring>

using namespace::std;

int main(){
	char in[102], out[102] = {0}, *alpha[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	cin >> in;
	int sum = 0;
	for (int i = 0; i < strlen(in); i++){
		sum += in[i] - '0';
	}
	int j = 0;
	while (sum != 0){
		out[j++] = sum % 10;
		sum = sum / 10;
	}
	while (out[--j] == 0&&j >= 0);
	for (int k = j; k > 0; k--){
		cout << alpha[out[k]] << ' ';
	}
	cout << alpha[out[0]];
}