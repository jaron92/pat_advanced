#include <iostream>
#include <string>
using namespace::std;

int main(){
	long long a, b, c;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a >> b >> c;
		long long result = a + b;
		bool ans;
		if (a>0 && b > 0 && result <= 0)
			ans = true;
		else if (a < 0 && b < 0 && result>=0)
			ans = false;
		else
			ans = (result>c);
		cout << "Case #" << i + 1 << ": ";
		if (ans)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}