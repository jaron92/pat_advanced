#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace::std;

string capit(string a){
	string b;
	for (int i = 0; i < a.size(); i++){
		if (a[i] >= 'a'&&a[i] <= 'z'){
			b += a[i] - 'a' + 'A';
		}
		else{
			b += a[i];
		}
	}
	return b;
}

int main(){
	string a, b;
	cin >> a >> b;
	a = capit(a);
	b = capit(b);
	int i, j;
	vector<char> broken;
	for (i = 0, j=0; i < a.size()&&j<b.size(); i++){
		if (a[i] == b[j]){
			j++;
		}
		else{
			if (find(broken.begin(), broken.end(), a[i]) == broken.end()){
				broken.push_back(a[i]);
			}
		}
	}
	for (int k = i; k < a.size(); k++){
		if (find(broken.begin(), broken.end(), a[k]) == broken.end()){
			broken.push_back(a[k]);
		}
	}
	for (int i = 0; i < broken.size(); i++){
		cout << broken[i];
	}
	return 0;
}