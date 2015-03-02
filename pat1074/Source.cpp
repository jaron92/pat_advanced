#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace::std;

typedef struct Node
{
	int addr, key;
}Node;

int main(){
	int st, n, stp;
	cin >> st >> n >> stp;
	map<int, int> addr2key, addr2next;
	vector<Node> people(n);
	vector<int> addrs;
	for (int i = 0; i < n; i++){
		int addr, key, next;
		cin >> addr >> key >> next;
		addr2key[addr] = key;
		addr2next[addr] = next;
	}
	int addr = st;
	while (addr != -1){
		addrs.push_back(addr);
		addr = addr2next[addr];
	}	
	int s1 = 0, s2 = 0;
	while (true){
		s2 = s1 + stp - 1;
		if (s2 >= addrs.size())
			break;
		for (int i = s1; i <= (s1 + s2) / 2; i++){
			int tmp = addrs[i];
			addrs[i] = addrs[s1 + s2 - i];
			addrs[s1 + s2 - i] = tmp;
		}
		s1 = s2 + 1;
	}
	cout.fill('0');
	for (int i = 0; i < addrs.size(); i++){
		cout << setw(5) << addrs[i] << ' ' << addr2key[addrs[i]] << ' ';
		if (i == addrs.size() - 1){
			cout << -1 << endl;
		}
		else{
			cout << setw(5) << addrs[i + 1] << endl;
		}
	}
	return 0;
}