#include <iostream>
#include <cstring>
using namespace::std;

char str1[1001], str[2003];
int main(){
	cin.getline(str1, 1001);
	for (int i = 0; i < strlen(str1); i++){
		str[2 * i] = -1;
		str[2 * i + 1] = str1[i];
	}
	str[2 * strlen(str1)] = -1;
	str[2 * strlen(str1) + 1] = '\0';
	int max = 0;
	for (int i = 0; i < strlen(str); i++){
		int j = i, k = i;
		while (str[j-1] == str[k+1] && j > 0 && k < strlen(str)-1){
			j--;
			k++;
		}
		int step = k - j + 1;
		if (step > max){
			max = step;
		}
	}
	cout << max / 2 << endl;
	return 0;
}