#include <iostream>
#include <stack>
#include <climits>
#define N 500

using namespace::std;

typedef struct graph{
	int matrix[N][N];
	int path_n[N];//路径条数
	int gather[N];//沿途可以召集的队伍数
	int teams[N];//每个节点的队伍数
	int n;
	int e;
}graph;

bool visited[N];
int dist[N];



void DijkstraPath(graph &g, int *dist, int v0, int v1){
	int i, j, k;
	for (i = 0; i < g.n; i++){//initialize dist[], path[]
		dist[i] = g.matrix[v0][i];
		visited[i] = false;
	}
	dist[v0] = 0;
	g.path_n[v0] = 1;
	g.gather[v0] = g.teams[v0];
	for (int i = 0; i < g.n; i++){
		int min = INT_MAX;
		int u;
		for (j = 0; j < g.n; j++){
			if (visited[j] == false && dist[j] >= 0 && dist[j] <= min){
				min = dist[j];
				u = j;
			}
		}
		visited[u] = true;
		if (u == v1)//reach v1 then jump out
			return;
		for (k = 0; k < g.n; k++){
			if (visited[k] == true || g.matrix[u][k] == INT_MAX)
				continue;

			if (min + g.matrix[u][k] < dist[k]){
				dist[k] = min + g.matrix[u][k];
				g.path_n[k] = g.path_n[u];
				g.gather[k] = g.gather[u] + g.teams[k];
			}
			else if (min + g.matrix[u][k] == dist[k]){
				g.path_n[k] += g.path_n[u];
				if (g.gather[k] < g.gather[u] + g.teams[k])
					g.gather[k] = g.gather[u] + g.teams[k];
			}
		}
	}
}


int main(){
	int n, e, c1, c2;
	graph g;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			g.matrix[i][j] = INT_MAX;
	cin >> n >> e >> c1 >> c2;
	g.n = n;
	g.e = e;
	for (int i = 0; i < n; i++){
		cin >> g.teams[i];
		g.path_n[i] = 0;
		g.gather[i] = 0;
	}
	for (int i = 0; i < e; i++){
		int a, b, c;
		cin >> a >> b;
		cin >> c;
		g.matrix[a][b] = g.matrix[b][a] = c;
	}
	DijkstraPath(g, dist, c1, c2);
	cout << g.path_n[c2] << ' ' << g.gather[c2];
}