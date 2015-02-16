#include <iostream>
#include <cstring>
#include <vector>
using namespace::std;

typedef struct account
{
	char name[11];
	char passwd[11];
	bool change;
}account;

int main(){
	int n, counter = 0;
	vector<account> acs;
	cin >> n;
	acs.resize(n);
	for (int i = 0; i < n; i++){
		cin >> acs[i].name >> acs[i].passwd;
		acs[i].change = false;
		for (int j = 0; j < strlen(acs[i].passwd); j++){
			char c = acs[i].passwd[j];
			switch (c)
			{
			case '1':
				acs[i].passwd[j] = '@';
				acs[i].change = true;
				break;
			case '0':
				acs[i].passwd[j] = '%';
				acs[i].change = true;
				break;
			case 'l':
				acs[i].passwd[j] = 'L';
				acs[i].change = true;
				break;
			case 'O':
				acs[i].passwd[j] = 'o';
				acs[i].change = true;
				break;
			default:
				break;
			}
		}
		if (acs[i].change == true){
			counter++;
		}
	}
	if (counter > 0){
		cout << counter << endl;
		for (int i = 0; i < n; i++){
			if (acs[i].change){
				cout << acs[i].name << ' ' << acs[i].passwd << endl;
			}
		}
	}
	else if (n == 1){
		cout << "There is 1 account and no account is modified" << endl;
	}
	else{
		cout << "There are " << n << " accounts and no account is modified" << endl;
	}
	return 0;
}