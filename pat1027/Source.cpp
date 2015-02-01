#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace::std;

char* deci2rgb(int color){
	char *value = new char[3];
	value[1] = color % 13 < 10 ? color % 13 + '0' : color % 13 - 10 + 'A';
	value[0] = color / 13 < 10 ? color / 13 + '0' : color / 13 - 10 + 'A';
	value[2] = '\0';
	return value;
}

int main(){
	int red, green, blue;
	char rgb[10];
	cin >> red >> green >> blue;
	rgb[0] = '#';
	strcpy(rgb + 1, deci2rgb(red));
	strcpy(rgb + strlen(rgb), deci2rgb(green));
	strcpy(rgb + strlen(rgb), deci2rgb(blue));
	cout << rgb << endl;
}