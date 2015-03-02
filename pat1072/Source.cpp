#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <iomanip>
#define MAX 1100
using namespace::std;

int mp[MAX][MAX];
int n, m, k, ds;
int dist[MAX];
bool visited[MAX];

void dijkstra(int st){
	int i, j, k;
	for (i = 1; i <= n + m; i++){
		dist[i] = mp[st][i];
		visited[i] = false;
	}
	dist[st] = 0;
	for (int i = 1; i <= n + m; i++){
		int min = INT_MAX;
		int u = -1;
		for (j = 1; j <= n + m; j++){
			if (visited[j] == false && dist[j] >= 0 && dist[j] <= min){
				min = dist[j];
				u = j;
			}
		}
		if (u == -1)
			continue;
		visited[u] = true;
		for (k = 1; k <= n + m; k++){
			if (visited[k] == true || mp[u][k] == -1)
				continue;

			if (min + mp[u][k] < dist[k] || dist[k] == -1){
				dist[k] = min + mp[u][k];
			}
		}
	}
}

int main(){
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			mp[i][j] = -1;
	cin >> n >> m >> k >> ds;
	for (int i = 0; i < k; i++){
		string str1, str2;
		int dist;
		cin >> str1 >> str2 >> dist;
		int s1, s2;
		s1 = str1[0] == 'G' ? n + atoi(str1.substr(1).c_str()) : atoi(str1.c_str());
		s2 = str2[0] == 'G' ? n + atoi(str2.substr(1).c_str()) : atoi(str2.c_str());
		mp[s2][s1] = mp[s1][s2] = dist;
	}
	int mini = -1, minimum = -1;
	double avgs = ds;
	for (int i = 1; i <= m; i++){
		dijkstra(n + i);
		double sum = 0;
		bool flag = false;
		int min = ds;
		for (int j = 1; j <= n; j++){
			if (dist[j]>ds || dist[j] == -1){
				flag = true;
				break;
			}
			sum += dist[j];
			if (dist[j] <= min){
				min = dist[j];
			}
		}
		if (flag)
			continue;
		if (min > minimum || min == minimum && sum / n < avgs){
			avgs = sum / n;
			mini = i;
			minimum = min;
		}
	}
	cout.setf(ios::fixed);
	if (mini == -1){
		cout << "No Solution" << endl;
	}
	else{
		cout << 'G' << mini << endl << setprecision(1) << double(minimum) << ' ' << setprecision(1) << avgs << endl;
	}
	return 0;
}