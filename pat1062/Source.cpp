#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace::std;

typedef struct person
{
	int id, virture, talent;
}person;

bool compare(person a, person b){
	int sum1 = a.talent + a.virture;
	int sum2 = b.talent + b.virture;
	if (a.talent == b.talent&&a.virture == b.virture)
		return a.id < b.id;
	else if (sum1 == sum2)
		return a.virture > b.virture;
	return sum1 > sum2;
}

int main(){
	int n, l, h;
	//cin >> n >> l >> h;
	scanf("%d%d%d", &n, &l, &h);
	vector<person> person_list, sage, nobleman, fool, rest, sorted_list;
	for (int i = 0; i < n; i++){
		person tmp;
		//cin >> tmp.id >> tmp.virture >> tmp.talent;
		scanf("%d%d%d", &tmp.id, &tmp.virture, &tmp.talent);
		if (tmp.virture >= l&&tmp.talent >= l){
			person_list.push_back(tmp);
		}
	}
	for (int i = 0; i < person_list.size(); i++){
		int talent = person_list[i].talent, virture = person_list[i].virture;
		if (talent >= h&&virture >= h)
			sage.push_back(person_list[i]);
		else if (talent < h&&virture >= h)
			nobleman.push_back(person_list[i]);
		else if (talent < h&&virture < h&&talent <= virture)
			fool.push_back(person_list[i]);
		else
			rest.push_back(person_list[i]);
	}
	sort(sage.begin(), sage.end(), compare);
	sort(nobleman.begin(), nobleman.end(), compare);
	sort(fool.begin(), fool.end(), compare);
	sort(rest.begin(), rest.end(), compare);
	cout << person_list.size() << endl;
	sorted_list.insert(sorted_list.end(), sage.begin(), sage.end());
	sorted_list.insert(sorted_list.end(), nobleman.begin(), nobleman.end());
	sorted_list.insert(sorted_list.end(), fool.begin(), fool.end());
	sorted_list.insert(sorted_list.end(), rest.begin(), rest.end());
	for (int i = 0; i < sorted_list.size(); i++){
		//cout << sorted_list[i].id << ' ' << sorted_list[i].virture << ' ' << sorted_list[i].talent << endl;
		printf("%d %d %d\n", sorted_list[i].id, sorted_list[i].virture, sorted_list[i].talent);
	}
	return 0;
}