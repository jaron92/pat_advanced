#include <iostream>

using namespace::std;


typedef struct node
{
	int value;
	struct node *next;
}node;

node tree[100];
int num[100] = { 0 }, deep;

void count_no_child(int root, int level){
	deep = level > deep ? level : deep;
	if (tree[root].next == NULL){
		num[level]++;
	}
	for (node *p = tree[root].next; p != NULL; p = p->next){
		count_no_child(p->value, level + 1);
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 100; i++)
		tree[i].next = NULL;
	for (int i = 0; i < m; i++){
		int id, k;
		cin >> id >> k;
		node *p = tree + id;
		for (int j = 0; j < k; j++){
			int childid;
			cin >> childid;
			p->next = new node;
			p->next->value = childid;
			p->next->next = NULL;
			p = p->next;
		}
	}
	count_no_child(1, 0);
	for (int i = 0; i < deep; i++)
		cout << num[i] << ' ';
	cout << num[deep];
}