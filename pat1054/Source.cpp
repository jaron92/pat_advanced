#include <iostream>
#include <map>
using namespace::std;

int main(){
	int m, n;
	cin >> m >> n;
	map<int, int> color_num;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			int color;
			cin >> color;
			auto it = color_num.find(color);
			if (it == color_num.end()){
				color_num[color] = 1;
			}
			else{
				color_num[color]++;
			}
		}
	}
	for (auto it = color_num.begin(); it != color_num.end(); it++){
		if (it->second>m*n / 2){
			cout << it->first << endl;
		}
	}
	return 0;
}