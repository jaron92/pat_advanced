#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cctype>
using namespace::std;

bool isalf(char c){
	return c >= '0'&&c <= '9' || c >= 'a'&&c <= 'z' || c >= 'A'&&c <= 'Z';
}

void toLowerCase(string& str){
	for (int i = 0; i < str.size(); i++)
		str[i] = tolower(str[i]);
}

int main(){
	string speech;
	map<string, int> counts;
	getline(cin, speech);
	toLowerCase(speech);
	int start = 0, end = 0;
	while (true){
		int i;
		for (i = end; i < speech.size(); i++){
			if (isalf(speech[i])){
				start = i;
				break;
			}
		}
		if (i == speech.size())
			break;
		for (i = start; i < speech.size(); i++){
			if (!isalf(speech[i])){
				end = i;
				break;
			}
		}
		if (i == speech.size())
			end = speech.size();
		string word = speech.substr(start, end - start);
		auto it = counts.find(word);
		if (it != counts.end()){
			it->second++;
		}
		else{
			counts[word] = 1;
		}
	}
	vector<string> max;
	int maxi = -1;
	for (auto it = counts.begin(); it != counts.end(); it++){
		if (it->second > maxi){
			max.clear();
			max.push_back(it->first);
			maxi = it->second;
		}
		else if (it->second == maxi){
			max.push_back(it->first);
		}
	}
	sort(max.begin(), max.end());
	cout << max[0] << ' ' << maxi;
	return 0;
}