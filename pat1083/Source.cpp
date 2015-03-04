#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace::std;

typedef struct Stu
{
	string name, id;
	int grade;
}Stu;
vector<Stu> people;
bool compare(int a, int b){
	return people[a].grade > people[b].grade;
}

int main(){
	int n;
	cin >> n;
	vector<int> rst;
	people.resize(n);
	for (int i = 0; i < n; i++){
		cin >> people[i].name >> people[i].id >> people[i].grade;
	}
	int s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < n; i++){
		if (people[i].grade >= s1&&people[i].grade <= s2){
			rst.push_back(i);
		}
	}
	sort(rst.begin(), rst.end(), compare);
	if (rst.size() == 0){
		cout << "NONE" << endl;
	}
	else{
		for (int i = 0; i < rst.size(); i++){
			int j = rst[i];
			cout << people[j].name << ' ' << people[j].id <<endl;
		}
	}
	return 0;
}