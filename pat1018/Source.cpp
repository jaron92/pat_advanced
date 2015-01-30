/*
≤Œ’’¥˙¬Îhttp://blog.csdn.net/sunbaigui/article/details/8657079
*/
#include <iostream>
#include <climits>
#include <vector>
using namespace::std;

#define N 501

int c[N], t[N][N];
int cmax, n, sp, m, minsend = INT_MAX, mincollect = INT_MAX;
bool visited[N];
int dist[N], last[N], gather[N];
vector<vector<int>> path;
vector<int> possiblepath;
vector<int> bestpath;


void DijkstraPath(int s, int ps){
	int i, j, k;
	for (i = 0; i < n + 1; i++){
		dist[i] = t[s][i];
		visited[i] = false;
	}
	dist[s] = 0;
	for (int i = 0; i < n + 1; i++){
		int min = INT_MAX;
		int u;
		for (j = 0; j < n + 1; j++){
			if (visited[j] == false && dist[j] >= 0 && dist[j] <= min){
				min = dist[j];
				u = j;
			}
		}
		visited[u] = true;
		for (k = 0; k < n + 1; k++){
			if (visited[k] == true || t[u][k] == INT_MAX)
				continue;

			if (min + t[u][k] < dist[k]){
				dist[k] = min + t[u][k];
				path[k].clear();
				path[k].push_back(u);
			}
			else if (min + t[u][k] == dist[k]){
				path[k].push_back(u);
			}
		}
	}
}

void FindBestPath(int u){
	possiblepath.push_back(u);
	if (u == 0){
		int send = 0, collect = 0;
		for (int i = possiblepath.size() - 1; i >= 0; i--){
			int index = possiblepath[i];
			int va = c[index] - cmax / 2;
			collect += va;
			if (collect < 0){
				send -= collect;
				collect = 0;
			}
		}
		if (send < minsend || send == minsend&&collect < mincollect) {
			minsend = send;
			mincollect = collect;
			bestpath = possiblepath;
		}
	}
	for (int i = 0; i < path[u].size(); i++){
		FindBestPath(path[u][i]);
		possiblepath.pop_back();
	}
}

int main(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			t[i][j] = INT_MAX;
		}
	}
	cin >> cmax >> n >> sp >> m;
	path.resize(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> c[i];
	}
	c[0] = cmax / 2;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			t[j][i] = t[i][j] = INT_MAX;
		}
	}
	for (int i = 0; i < m; i++){
		int si, sj, tmp;
		cin >> si >> sj;
		cin >> tmp;
		t[si][sj] = t[sj][si] = tmp;
	}
	DijkstraPath(0, sp);
	FindBestPath(sp);
	cout << minsend << ' ';
	for (int i = bestpath.size() - 1; i > 0; i--){
		cout << bestpath[i] << "->";
	}
	cout << bestpath[0] << ' ' << mincollect << endl;

}