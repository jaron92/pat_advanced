#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace::std;

typedef struct station
{
	float price;
	int distance;
	float remain;//到达此加油站时剩下的油
	float amount;//加的油钱
}station;

int cmax, d, davg, n, flag = 0, stprice;
vector<station> stlist, stlbyd;

bool compare(station s1, station s2){
	return s1.distance < s2.distance;
}

int main(){
	cin >> cmax >> d >> davg >> n;
	//cout << cmax*davg << endl;
	cout.setf(ios::fixed);
	for (int i = 0; i < n; i++){
		station *st = new station;
		cin >> st->price >> st->distance;
		if (st->distance == 0){
			st->remain = 0;
			flag = 1;
		}
		stlist.push_back(*st);
		
	}
	if (flag == 0){
		cout << "The maximum travel distance = 0.00" << endl;
		return 0;
	}
	sort(stlist.begin(), stlist.end(), compare);
	float sum = 0;
	vector<station>::iterator st = stlist.begin(), end, min;
	while (true){
		min = st;
		for (vector<station>::iterator it = st + 1; it != stlist.end(); it++){
			if (it->distance - st->distance <= cmax*davg){
				if (it->price <= st->price){
					min = it;
					min->remain = 0;
					st->amount = st->price*((min->distance - st->distance)*1.0 / davg - st->remain);
					break;
				}
				if (min == st&&st->distance + cmax*davg < d){
					min = it;
				}
				if (it->price < min->price){
					min = it;
				}
				st->amount = (cmax - st->remain)*st->price;
				min->remain = cmax - (it->distance - st->distance)*1.0 / davg;
			}
		}
		//cout << "min:" << min->distance << ' ' << min->remain << endl;
		if (min == st){
			if (st->distance + cmax*davg >= d){
				//cout << st->distance << ' ' << st->remain << endl;
				sum += ((d - st->distance)*1.0 / davg - st->remain)*st->price;
				break;
			}
			else{
				sum = st->distance + cmax* davg;
				cout << "The maximum travel distance = " << setprecision(2) << sum << endl;
				return 0;
			}
		}
		//cout << st->distance << ' ' << st->amount << endl;
		sum += st->amount;
		st = min;
	}
	cout << setprecision(2) << sum << endl;
	return 0;
}