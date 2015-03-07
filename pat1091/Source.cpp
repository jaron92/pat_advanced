#include <iostream>
#include <vector>
#include <queue>
using namespace::std;

int matrix[1286][128][60];
int visited[1286][128][60];
int vx[] = { 1, -1, 0, 0, 0, 0 };
int vy[] = { 0, 0, 1, -1, 0, 0 };
int vz[] = { 0, 0, 0, 0, 1, -1 };
int m, n, l, t, counter = 0;

typedef struct node
{
	int x, y, z;
	node(int _x, int _y, int _z) :x(_x), y(_y), z(_z){}
}node;

void BFS(int x, int y, int z, int t){
	queue<node> q;
	node tmp(x, y, z);
	q.push(tmp);
	int sum = 1;
	visited[x][y][z]=1;
	while (!q.empty()){
		node head = q.front();
		q.pop();
		int hx = head.x;
		int hy = head.y;
		int hz = head.z;
		for (int i = 0; i < 6; i++){
			int px = hx + vx[i];
			int py = hy + vy[i];
			int pz = hz + vz[i];
			if (px < 0 || px >= m || py < 0 || py >= n || pz < 0 || pz >= l){

			}
			else if (matrix[px][py][pz] == 1 && !visited[px][py][pz]){
				sum++;
				visited[px][py][pz] = 1;
				node tmp(px, py, pz);
				q.push(tmp);
			}
		}
	}
	if (sum >= t){
		counter += sum;
	}
}

int main(){
	cin >> m >> n >> l >> t;
	for (int i = 0; i < l; i++){
		for (int j = 0; j < m; j++){
			for (int k = 0; k < n; k++){
				cin >> matrix[j][k][i];
			}
		}
	}
	for (int i = 0; i < l; i++){
		for (int j = 0; j < m; j++){
			for (int k = 0; k < n; k++){
				if (matrix[j][k][i] == 1 && !visited[j][k][i])
					BFS(j, k, i, t);
			}
		}
	}
	cout << counter << endl;
} 