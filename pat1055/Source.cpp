#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace::std;

typedef struct person
{
	string name;
	int age, worth;
}person;

vector<person> input_list, person_list;

bool compare_by_worth(person a, person b){
	if (a.worth == b.worth&&a.age == b.age)
		return a.name < b.name;
	else if (a.worth == b.worth)
		return a.age < b.age;
	return a.worth > b.worth;
}

int main(){
	int n, k;
	map<int, int> person_counter;
	cin >> n >> k;
	input_list.resize(n);
	for (int i = 0; i < n; i++){
		cin >> input_list[i].name >> input_list[i].age >> input_list[i].worth;
		
	}
	sort(input_list.begin(), input_list.end(), compare_by_worth);
	for (int i = 0; i < n; i++){
		auto it = person_counter.find(input_list[i].age);
		if (it == person_counter.end()){
			person_counter[input_list[i].age] = 1;
		}
		else{
			if (it->second > 100){
				continue;
			}
			it->second++;
		}
		person_list.push_back(input_list[i]);
	}
	for (int i = 0; i < k; i++){
		cout << "Case #" << i + 1 << ':' << endl;
		int max, amin, amax;
		cin >> max >> amin >> amax;
		int counter = 1;
		for (int j = 0; j < n;j++){
			if (person_list[j].age >= amin&&person_list[j].age <= amax){
				cout << person_list[j].name << ' ' << person_list[j].age << ' ' << person_list[j].worth << endl;
				if (counter++ >= max)
					break;
			}
		}
		if (counter == 1){
			cout << "None" << endl; 
			continue;
		}
	}
	return 0;
}