#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace::std;

typedef struct log
{
	char id[16];
	char login_t[9];
	char logout_t[9];
}visit_log;



int main(){
	int m, maxi, mini;
	char min[9] = "23:59:59", max[9] = "00:00:00";
	visit_log *p;
	cin >> m;
	p = new visit_log[m];
	for (int i = 0; i < m; i++){
		cin >> p[i].id >> p[i].login_t >> p[i].logout_t;
		if (strcmp(min, p[i].login_t) > 0){
			strcpy(min, p[i].login_t);
			mini = i;
		}
		if (strcmp(p[i].logout_t, max) > 0){
			strcpy(max, p[i].logout_t);
			maxi = i;
		}
	}
	cout << p[mini].id << ' ' << p[maxi].id;
	return 0;
}