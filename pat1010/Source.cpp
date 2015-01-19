/*参考http://blog.csdn.net/wzb56_earl/article/details/7330762的二项查找写法*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <climits>

using namespace::std;

int main(){
	long tag, radix, value=0, coe=1;
	char a[12], b[12], c[12], d[12];
	cin >> a >> b >> tag >> radix;
	strcpy(c, tag == 1 ? a : b);
	strcpy(d, tag == 2 ? a : b);
	for (int i = strlen(c) - 1; i >= 0; i--){
		long num = isdigit(c[i]) ? c[i] - '0' : c[i] - 'a' + 10;
		value += coe*num;
		coe *= radix;
	}
	char max = 0;
	for (int i = strlen(d) - 1; i >= 0; i--){
		if (d[i] > max)
			max = d[i];
	}
	long value_d = 0, rad, flag = 0;
	long left = isdigit(max) ? max - '0'+1 : max - 'a' + 11;
	long right = value > left ? value +1: left+1;
	rad = left;
	while (left <= right){
		value_d = 0;
		coe = 1;
		for (int i = strlen(d) - 1; i >= 0; i--){
			long num = isdigit(d[i]) ? d[i] - '0' : d[i] - 'a' + 10;
			value_d += coe*num;
			if (value_d > value)
				break;
			coe *= rad;
		}
		if (value_d > value)
			right = rad-1;
		else if (value_d < value)
			left = rad+1;
		else{
			flag = 1;
			break;
		}
		rad = (left + right) / 2;
	}
	if (flag == 1){
		cout << rad;
	}
	else{
		cout << "Impossible";
	}
}