#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace::std;

vector<vector<int> > graph;
vector<bool> visited;
vector<int> pre, bm, st;
int n;


void dfs(int v, int step){
	visited[v] = true;
	st[v] = step;
	//cout << v << ' ' << step << endl;
	for (vector<int>::iterator iter = graph[v].begin(); iter != graph[v].end(); iter++){
		if (!visited[*iter])
			dfs(*iter, step + 1);
	}
}

int Find(int x){
	int r = x;
	while (pre[r] != r)
		r = pre[r];
	return r;
}

void join(int x, int y){
	int fx = Find(x), fy = Find(y);
	//cout << "fx:" << fx << ' ' << "fy:" << fy << endl;
	if (fx != fy)
		pre[fx] = fy;
}

int main(){
	int s = 1;
	cin >> n;
	graph.resize(n + 1);
	visited.assign(n + 1, false);
	bm.assign(n + 1, 0);
	pre.resize(n + 1);
	st.assign(n + 1, 0);
	for (int i = 1; i <= n; i++)
		pre[i] = i;
	for (int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		join(a, b);
		s = (s == -1) ? a : s;
	}
	for (int i = 1; i <= n; i++){
		bm[Find(i)] = 1;
	}
	int counter = 0;
	for (int i = 1; i <= n; i++){
		if (bm[i])
			counter++;
	}
	if (counter != 1){
		cout << "Error: " << counter << " components";
		return 0;
	}
	dfs(s, 0);
	int max = INT_MIN;
	vector<int> maxi;
	for (int i = 1; i <= n; i++){
		if (st[i] > max){
			max = st[i];
			maxi.clear();
			maxi.push_back(i);
		}
		else if (st[i] == max){
			maxi.push_back(i);
		}
	}
	st.assign(n + 1, 0);
	visited.assign(n + 1, false);
	dfs(maxi[0], 0);
	vector<int> mostfar;
	max = INT_MIN;
	for (int i = 1; i <= n; i++){
		if (st[i] > max){
			max = st[i];
			mostfar.clear();
			mostfar.push_back(i);
		}
		else if (st[i] == max){
			mostfar.push_back(i);
		}
	}
	if (n != 1){
		for (vector<int>::iterator it = maxi.begin(); it != maxi.end(); it++){
			if (find(mostfar.begin(),mostfar.end(), *it) == mostfar.end())
				mostfar.push_back(*it);
		}
		
	}
	sort(mostfar.begin(), mostfar.end());
	for (vector<int>::iterator it = mostfar.begin(); it != mostfar.end(); it++)
		cout << *it << endl;
	
}
