/*
参考代码http://blog.csdn.net/sunbaigui/article/details/8657062
自己尝试用sort unique去做名字的排序去重但是一直都过不了索性还是用vector来存，最后的思路大部分参照上面的代码
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

using namespace::std;

typedef struct call
{
	string name;
	string time;
	bool on;
}call;

int price[24];
call record[1000];
vector<call> calls;

bool compare(call a, call b){
	if (a.name < b.name)
		return true;
	else if (a.name == b.name&&a.time < b.time)
		return true;
	else
		return false;
}

int caculate_money(int d, int h, int m){
	int dayprice = 0, sum=0;
	for (int i = 0; i < 24; i++){
		dayprice += price[i] * 60;
	}
	sum += d*dayprice + m*price[h];
	for (int i = 0; i < h; i++){
		sum += price[i] * 60;
	}
	return sum;
}

int main(){
	for (int i = 0; i < 24; i++)
		cin >> price[i];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string type;
		cin >> record[i].name >> record[i].time >> type;
		if (type == "on-line")
			record[i].on = true;
		else
			record[i].on = false;
	}
	sort(record, record + n, compare);
	call *first, *end;
	float totalamount = 0;
	cout.fill('0');
	cout.setf(ios::fixed);
	first = NULL;
	for (int i = 0; i < n; i++){
		if (record[i].on == true&&first==NULL){
			calls.push_back(record[i]);
			first = record + i;
		}
		else if (first != NULL&&record[i].on == false&&record[i].name==first->name){
			calls.push_back(record[i]);
			first = NULL;
		}
		else if (first != NULL&&record[i].on == true){
			calls.pop_back();
			calls.push_back(record[i]);
			first = record + i;
		}
	}
	if (calls.back().on == true)
		calls.pop_back();
	string tmpname = string("\0");
	for (int i = 0; i < calls.size(); i+=2){
		if (calls[i].name != tmpname){
			if (tmpname != string("\0")){
				cout << "Total amount: $" << setprecision(2) << totalamount*0.01 << endl;
			}
			cout << calls[i].name << ' ' << string(calls[i].time, 0, calls[i].time.find_first_of(':')) << endl;
			tmpname = calls[i].name;
			totalamount = 0;
		}
		int d1, d2, h1, h2, m1, m2, sum, dayprice, total;
		first = &calls[i];
		end = &calls[i + 1];
		sum = 0;
		dayprice = 0;
		total = 0;
		d1 = atoi(first->time.substr(3, 5).c_str());
		h1 = atoi(first->time.substr(6, 8).c_str());
		m1 = atoi(first->time.substr(9, 11).c_str());
		cout << setw(2) << d1 << ':' << setw(2) << h1 << ':' << setw(2) << m1 << ' ';
		d2 = atoi(end->time.substr(3, 5).c_str());
		h2 = atoi(end->time.substr(6, 8).c_str());
		m2 = atoi(end->time.substr(9, 11).c_str());
		cout << setw(2) << d2 << ':' << setw(2) << h2 << ':' << setw(2) << m2 << ' ';
		sum += (d2 - d1) * 24 * 60 + (h2 - h1) * 60 + (m2 - m1);
		total = caculate_money(d2, h2, m2) - caculate_money(d1, h1, m1);
		totalamount += total;
		cout << sum << " $" << setprecision(2) << total*0.01 << endl;
	}
	cout << "Total amount: $" << setprecision(2) << totalamount*0.01 << endl;
	return 0;
}