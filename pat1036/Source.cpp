#include <iostream>
#include <string>
#include <climits>
using namespace::std;

int main(){
	int n;
	cin >> n;
	string maleName, femaleName, maleId, femaleId;
	int maleGrade = INT_MAX, femaleGrade = INT_MIN;
	for (int i = 0; i < n; i++){
		string name, id;
		char gender;
		int grade;
		cin >> name >> gender >> id >> grade;
		if (gender == 'M' && grade < maleGrade){
			maleGrade = grade;
			maleName = name;
			maleId = id;
		}
		if (gender == 'F' && grade > femaleGrade){
			femaleGrade = grade;
			femaleName = name;
			femaleId = id;
		}
	}
	int difference = 0;
	if (femaleGrade == INT_MIN){
		cout << "Absent" << endl;
		difference = INT_MAX;
	}
	else{
		cout << femaleName << ' ' << femaleId << endl;
	}
	if (maleGrade == INT_MAX){
		cout << "Absent" << endl;
		difference = INT_MAX;
	}
	else {
		cout << maleName << ' ' << maleId << endl;
	}
	if (difference == INT_MAX){
		cout << "NA" << endl;
	}
	else{
		cout << femaleGrade - maleGrade << endl;
	}
	return 0;
}