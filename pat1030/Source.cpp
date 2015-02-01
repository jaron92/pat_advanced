#include <iostream>
#include <climits>
#include <vector>
using namespace::std;

#define N 501

int distan[N][N], cost[N][N];
int n, m, st, ed;
bool visited[N];
int dist[N], co[N];
vector<vector<int>> path;
vector<int> bestpath;


void DijkstraPath(int s, int ed){
	int i, j, k;
	for (i = 0; i < n + 1; i++){
		dist[i] = distan[s][i];
		co[i] = cost[s][i];
		visited[i] = false;
	}
	dist[s] = 0;
	co[s] = 0;
	for (int i = 0; i < n + 1; i++){
		int min = INT_MAX, minco = INT_MAX;
		int u;
		for (j = 0; j < n + 1; j++){
			if (visited[j] == false && dist[j] >= 0 && (dist[j] < min || dist[j] == min&&co[j]<minco)){
				min = dist[j];
				minco = co[j];
				u = j;
			}
		}
		if (u == ed)
			return;
		visited[u] = true;
		for (k = 0; k < n + 1; k++){
			if (visited[k] == true || distan[u][k] == INT_MAX)
				continue;
			if (min + distan[u][k] < dist[k] || min + distan[u][k] == dist[k] && minco + cost[u][k] < co[k]){
				dist[k] = min + distan[u][k];
				co[k] = minco + cost[u][k];
				path[k].clear();
				path[k].push_back(u);
			}
			if (min + distan[u][k] == dist[k]&&u == st)
				path[k].push_back(u);
		}
	}
}

void FindBestPath(int st, int ed){
	bestpath.push_back(ed);
	if (ed == st)
		return;
	FindBestPath(st, path[ed][0]);
}

int main(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			distan[i][j] = INT_MAX;
			cost[i][j] = INT_MAX;
		}
	}
	cin >> n >> m >> st >> ed;
	for (int i = 0; i < m; i++){
		int c1, c2, d, c;
		cin >> c1 >> c2 >> d >> c;
		distan[c1][c2] = distan[c2][c1] = d;
		cost[c1][c2] = cost[c2][c1] = c;
	}
	path.resize(n);
	DijkstraPath(st, ed);
	FindBestPath(st, ed);
	for (int i = bestpath.size() - 1; i >= 0; i--){
		cout << bestpath[i] << " ";
	}
	cout << dist[ed] << " " << co[ed];
	return 0;
}