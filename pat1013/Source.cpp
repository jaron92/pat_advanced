#include <iostream>
#include <vector>

using namespace::std;

vector<int> visited;
int a[1000][1000] = { 0 }, num=0;

void bfs(int n, int v, int concern){
	visited[v] = 1;
	for (int i = 1; i <= n; i++){
		if ((a[v][i] == 1 || a[i][v] == 1) && !visited[i] && i != concern){
			bfs(n, i, concern);
		}
	}
}

int main(){
	int concern[1000];
	int n, m, k;
	cin >> n >> m >> k;
	visited.resize(n+1);
	for (int i = 0; i < m; i++){
		int c1, c2;
		cin >> c1 >> c2;
		a[c1][c2] = 1;
	}
	for (int i = 0; i < k; i++)
		cin >> concern[i];
	for (int i = 0; i < k; i++){
		num = 0;
		visited.assign(n + 1, 0);
		for (int j = 1; j <= n; j++){
			if (j == concern[i])
				continue;
			if (!visited[j]){
				bfs(n, j, concern[i]);
				num++;
			}
		}
		cout << num - 1 << endl;
	}
	
	return 0;
}