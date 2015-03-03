#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace::std;

string find_common(string a, string b){
	if (a.size() == 0 || b.size() == 0)
		return string();
	int ed1 = a.size() - 1, ed2 = b.size() - 1;
	while (a[ed1] == b[ed2]){
		ed1--;
		ed2--;
		if (ed1 == -1 || ed2 == -1)
			break;
	}
	return a.substr(ed1 + 1);
}

int main(){
	int n;
	cin >> n;
	getchar();
	vector<string> sen(n);
	for (int i = 0; i < n; i++){
		getline(cin, sen[i]);
	}
	string suffix = find_common(sen[0], sen[1]);
	for (int i = sen.size() - 1; i >= 2; i--){
		suffix = find_common(suffix, sen[i]);
	}
	if (suffix.size() == 0){
		cout << "nai" << endl;
	}
	else{
		cout << suffix << endl;
	}
	return 0;
}