#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace::std;
typedef long long ll;

ll find_comm(ll den1, ll den2){
	ll m = den1, n = den2;
	while (n != 0){
		ll l = m%n;
		m = n;
		n = l;
	}
	return m;
}

pair<ll, ll> sum(pair<ll, ll> a, pair<ll, ll> b){
	ll num1, num2, den1, den2;
	num1 = a.first;
	num2 = b.first;
	den1 = a.second;
	den2 = b.second;
	ll comm = den1*den2 / find_comm(den1, den2);
	ll add = num1*comm / den1 + num2*comm / den2;

	return make_pair(add / find_comm(abs(add), comm), comm / find_comm(abs(add), comm));
}

int main(){
	int n;
	cin >> n;
	vector<pair<ll, ll> > nums;
	auto rst = make_pair(0, 1);
	for (int i = 0; i < n; i++){
		string ra;
		cin >> ra;
		ll num, den;
		ll po = ra.find('/');
		num = atoi(ra.substr(0, po).c_str());
		den = atoi(ra.substr(po + 1).c_str());
		if (den < 0){
			num *= -1;
			den *= -1;
		}
		rst = sum(rst, make_pair(num, den));
	}
	ll comm = find_comm(abs(rst.first), abs(rst.second));
	ll num = rst.first / comm;
	ll den = rst.second / comm;
	if (num / den != 0)
		cout << num / den; 
	if (num / den != 0 && num%den != 0)
		cout << ' ';
	if (num%den != 0)
		cout << num%den << '/' << den << endl;
	if (num == 0){
		cout << '0' << endl;
	}
	return 0;
}