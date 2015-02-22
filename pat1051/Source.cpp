#include <iostream>
#include <stack>
using namespace::std;

int main(){
	int n, m, k, flag;
	stack<int> st;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++){
		int counter = 1;
		flag = 0;
		for (int j = 0; j < n; j++){
			int num;
			cin >> num;
			while ((st.empty() || st.top() != num) && st.size()<m + 1){
				st.push(counter++);
			}
			if (st.size()==m+1){
				flag = 1;
			}
			st.pop();
		}
		while (!st.empty())
			st.pop();
		if (flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}