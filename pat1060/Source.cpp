#include <iostream>
#include <string>
#include <vector>
using namespace::std;

void GetSig(vector<char>& sig, string& a, int n, int st){
	int counter = st;
	for (int i = st; sig.size() < n; i++){
		if (i < a.size()){
			if (a[i] != '.'){
				sig.push_back(a[i]);
			}
		}
		else{
			sig.push_back('0');
		}
	}
}

int main(){
	int n;
	string a, b;
	cin >> n >> a >> b;
	int dot1, dot2, st1, st2, k1, k2;
	dot1 = a.find('.') == string::npos ? a.size() : a.find('.');
	dot2 = b.find('.') == string::npos ? b.size() : b.find('.');
	st1 = a.find_first_not_of('0', a.find_first_not_of('0') == dot1 ? dot1 + 1 : 0);
	st2 = b.find_first_not_of('0', b.find_first_not_of('0') == dot2 ? dot2 + 1 : 0);
	st1 = st1 == string::npos ? dot1 : st1;
	st2 = st2 == string::npos ? dot2 : st2;
	k1 = st1 > dot1 ? dot1 - st1 + 1 : dot1 - st1;
	k2 = st2 > dot2 ? dot2 - st2 + 1 : dot2 - st2;;
	vector<char> sig1, sig2;
	GetSig(sig1, a, n, st1);
	GetSig(sig2, b, n, st2);
	if (sig1 == sig2&&k1 == k2){
		cout << "YES 0.";
		for (int i = 0; i < sig1.size(); i++){
			cout << sig1[i];
		}
		if (k1 != 0)
			cout << "*10^" << k1 << endl;
	}else{
		cout << "NO ";
		cout << "0.";
		for (int i = 0; i < sig1.size(); i++){
			cout << sig1[i];
		}
		if (k1 != 0)
			cout << "*10^" << k1;
		cout << " 0.";
		for (int i = 0; i < sig2.size(); i++){
			cout << sig2[i];
		}
		if (k2 != 0)
			cout << "*10^" << k2 << endl;
	}
	return 0;
}