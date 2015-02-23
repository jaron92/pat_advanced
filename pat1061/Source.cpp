#include <iostream>
#include <string>
#include <iomanip>
using namespace::std;

bool isCap(char c){
	return c >= 'A'&&c <= 'Z';
}

bool isNum(char c){
	return c >= '0'&&c <= '9';
}

bool isAlf(char c){
	return c >= 'A'&&c <= 'Z' || c >= 'a'&&c <= 'z';
}

bool isHour(char c){
	return c >= '0'&&c <= '9' || c >= 'A'&&c <= 'N';
}

bool isWeek(char c){
	return c >= 'A'&&c <= 'G';
}

char *week[] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int main(){
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int len1 = s1.size() > s2.size() ? s2.size() : s1.size();
	int len2 = s3.size() > s4.size() ? s4.size() : s3.size();
	int day, hour, minute;
	int counter = 0;
	for (int i = 0; i < len1; i++){
		if (s1[i] == s2[i]){
			if (counter == 1 && isHour(s1[i])){
				if (isNum(s1[i]))
					hour = s1[i] - '0';
				if (isCap(s1[i]))
					hour = s1[i] - 'A' + 10;
				counter++;
			}
			if (isWeek(s1[i]) && counter == 0){
				day = s1[i] - 'A';
				counter++;
			}
		}
	}
	for (int i = 0; i < len2; i++){
		if (s3[i] == s4[i]&&isAlf(s3[i])){
			minute = i;
			break;
		}
	}
	cout.fill('0');
	cout << week[day] << ' ' << setw(2) << hour << ':' << setw(2) << minute;
}