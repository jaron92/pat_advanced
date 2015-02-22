#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace::std;

typedef struct node
{
	int addr, key, next;
}node;

bool compare(node a, node b){
	return a.key < b.key;
}

int main(){
	int n, start;
	cin >> n >> start;
	vector<node> input_list(n), link_list;
	map<int, int> map_addr;
	for (int i = 0; i < n; i++){
		cin >> input_list[i].addr >> input_list[i].key >> input_list[i].next;
		map_addr[input_list[i].addr] = i;
	}
	int addr = start, flag = 0;
	while (addr != -1){
		auto it = map_addr.find(addr);
		if (it == map_addr.end()){
			flag = 1;
			break;
		}
		node nod = input_list[it->second];
		link_list.push_back(nod);
		addr = nod.next;
	}
	cout.fill('0');
	if (link_list.empty()){
		if (flag)
			cout << "0 " << setw(5) << start << endl;
		else
			cout << "0 -1" << endl;
	}
	else {
		sort(link_list.begin(), link_list.end(), compare);
		for (int i = 0; i < link_list.size() - 1; i++){
			link_list[i].next = link_list[i + 1].addr;
		}
		link_list[link_list.size() - 1].next = -1;
		cout << link_list.size() << ' ' << setw(5) << link_list[0].addr << endl;
		for (int i = 0; i < link_list.size(); i++){
			cout << setw(5) << link_list[i].addr << ' ' << link_list[i].key << ' ';
			if (link_list[i].next != -1)
				cout << setw(5) << link_list[i].next << endl;
			else
				cout << link_list[i].next << endl;
		}
	}
	return 0;
}