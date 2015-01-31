#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace::std;

typedef struct book
{
	string id;
	string title;
	string author;
	vector<string> keywords;
	string publisher;
	int publish_year;
}book;

vector<book> db;

void search(int type, string &query){
	vector<string> result;
	for (vector<book>::iterator it = db.begin(); it != db.end(); it++){
		switch (type)
		{
		case 1:
			if (it->title == query)
				result.push_back(it->id);
			break;
		case 2:
			if (it->author == query)
				result.push_back(it->id);
			break;
		case 3:
			for (vector<string>::iterator iter = it->keywords.begin(); iter != it->keywords.end(); iter++){
				if (*iter == query){
					result.push_back(it->id);
					break;
				}
			}
			break;
		case 4:
			if (it->publisher == query)
				result.push_back(it->id);
			break;
		case 5:
			if (it->publish_year == atoi(query.c_str()))
				result.push_back(it->id);
			break;
		default:
			break;
		}
	}
	sort(result.begin(), result.end());
	if (result.empty()){
		cout << "Not Found" << endl;
		return;
	}
	for (vector<string>::iterator it = result.begin(); it != result.end(); it++)
		cout << *it << endl;
}


int main(){
	int n;
	cin >> n;
	db.resize(n);
	for (vector<book>::iterator it = db.begin(); it != db.end(); it++){
		cin >> it->id;
		getchar();
		getline(cin, it->title);
		getline(cin, it->author);
		string line;
		getline(cin, line);
		int po = 0, pre=0;
		while ((po = line.find(" ", po)) != string::npos){
			//cout << string(line, pre, po - pre) << endl;
			it->keywords.push_back(string(line, pre, po - pre));
			pre = ++po;
		}
		it->keywords.push_back(string(line, pre, line.length()));
		getline(cin, it->publisher);
		cin >> it->publish_year;
	}
	int m;
	cin >> m;
	getchar();
	for (int i = 0; i < m; i++){
		string line, query;
		int type;
		getline(cin, line);
		type = atoi(string(line, 0, line.find(" ") - 1).c_str());
		query = string(line, line.find(" ") + 1, line.length());
		cout << line << endl;
		search(type, query);
	}
}