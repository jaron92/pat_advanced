#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace::std;

typedef struct stu
{
	char id[10];
	char name[10];
	int grade;
}stu;

stu stulist[100000];

bool CompareById(stu a, stu b){
	return strcmp(a.id, b.id) < 0;
}

bool CompareByName(stu a, stu b){
	if (strcmp(a.name, b.name) == 0)
		return strcmp(a.id, b.id) < 0;
	return strcmp(a.name, b.name) < 0;
}

bool CompareByGrade(stu a, stu b){
	if (a.grade == b.grade)
		return strcmp(a.id, b.id) < 0;
	return a.grade < b.grade;
}

int main(){
	int n, c;
	//cin >> n >> c;
	char id[10], name[10];
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++){
		stu *item = stulist + i;
		//cin >> item->id;
		//cin >> item->name;
		//cin >> item->grade;
		scanf("%s%s%d", item->id, item->name, &item->grade);
	}

	switch (c)
	{
	case 1:
		sort(stulist, stulist + n, CompareById);
		break;
	case 2:
		sort(stulist, stulist + n, CompareByName);
		break;
	case 3:
		sort(stulist, stulist + n, CompareByGrade);
		break;
	default:
		break;
	}
	for (int i = 0; i < n; i++){
		stu *it = stulist + i;
		printf("%s %s %d\n", it->id, it->name, it->grade);
	}
}