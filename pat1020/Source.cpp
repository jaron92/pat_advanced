#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace::std;

typedef struct node
{
	int value;
	struct node *left, *right;
	node(int v = -1, node *l = NULL, node *r = NULL)
		:value(v), left(l), right(r){};
}node;

vector<int> post, in, level;
queue<node*> qu;

node* CreateTreeFromOrder(vector<int>::iterator start, vector<int>::iterator end){
	int v = *(post.end() - 1);
	if (!post.empty())
		post.pop_back();
	node* root = new node(v);
	vector<int>::iterator iter = find(start, end, v);
	root->right = (iter == end - 1) ? NULL : CreateTreeFromOrder(iter + 1, end);
	root->left = (iter == start) ? NULL : CreateTreeFromOrder(start, iter);
	return root;
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int m;
		cin >> m;
		post.push_back(m);
	}
	for (int i = 0; i < n; i++){
		int m;
		cin >> m;
		in.push_back(m);
	}
	node* head = CreateTreeFromOrder(in.begin(), in.end());
	qu.push(head);
	while (!qu.empty()){
		if (qu.front() == NULL){
			qu.pop();
			continue;
		}
		level.push_back(qu.front()->value);
		qu.push(qu.front()->left);
		qu.push(qu.front()->right);
		qu.pop();
	}
	for (vector<int>::iterator iter = level.begin(); iter != level.end() - 1; iter++)
		cout << *iter << ' ';
	cout << *(level.end() - 1);
	return 0;
}