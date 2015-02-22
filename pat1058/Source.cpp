#include <iostream>
#include <cstring>
#include <string>
using namespace::std;

int main(){
	string a, b;
	cin >> a >> b;
	int Galleon1, Galleon2, Galleon, Sickle1, Sickle2, Sickle, Knut1, Knut2, Knut;
	int p1 = a.find('.'), p2 = a.rfind('.');
	Galleon1 = atoi(a.substr(0, p1).c_str());
	Sickle1 = atoi(a.substr(p1 + 1, p2 - p1 - 1).c_str());
	Knut1 = atoi(a.substr(p2 + 1).c_str());
	p1 = b.find('.');
	p2 = b.rfind('.');
	Galleon2 = atoi(b.substr(0, p1).c_str());
	Sickle2 = atoi(b.substr(p1 + 1, p2 - p1 - 1).c_str());
	Knut2 = atoi(b.substr(p2 + 1).c_str());
	Knut = (Knut1 + Knut2) % 29;
	int c = (Knut1 + Knut2) / 29;
	Sickle = (Sickle1 + Sickle2 + c) % 17;
	c = (Sickle1 + Sickle2 + c) / 17;
	Galleon = Galleon1 + Galleon2 + c;
	cout << Galleon << '.' << Sickle << '.' << Knut;
	return 0;
}