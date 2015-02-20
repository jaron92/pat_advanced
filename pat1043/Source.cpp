/*²Î¿¼´úÂëhttp://blog.csdn.net/sunbaigui/article/details/8656947*/
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace::std;

typedef struct Node
{
	int key;
	Node* left;
	Node* right;
	Node(Node* l = NULL, Node* r = NULL, int k = -1)
		:left(l), right(r), key(k){};
}Node;

void tree_insert(Node** tree, int key){
	Node** p = tree;
	while ((*p) != NULL){
		if ((*p)->key > key){
			p = &(*p)->left;
		}
		else{
			p = &(*p)->right;
		}
	}
	(*p) = new Node;
	(*p)->key = key;
}

void tree_rrl_travel(Node* tree, vector<int> &v){
	if (tree == NULL)
		return;
	v.push_back(tree->key);
	tree_rrl_travel(tree->right, v);
	tree_rrl_travel(tree->left, v);
}

void tree_rlr_travel(Node* tree, vector<int> &v){
	if (tree == NULL)
		return;
	v.push_back(tree->key);
	tree_rlr_travel(tree->left, v);
	tree_rlr_travel(tree->right, v);
}

void tree_lrroot_travel(Node* tree, vector<int> &v){
	if (tree == NULL)
		return;
	tree_lrroot_travel(tree->left, v);
	tree_lrroot_travel(tree->right, v);
	v.push_back(tree->key);
}

void tree_rlroot_travel(Node* tree, vector<int> &v){
	if (tree == NULL)
		return;
	tree_rlroot_travel(tree->right, v);
	tree_rlroot_travel(tree->left, v);
	v.push_back(tree->key);
}

int main(){
	int n;
	cin >> n;
	vector<int> invec(n), lvec, rvec, outvec;
	for (int i = 0; i < n; i++){
		cin >> invec[i];
	}
	Node* tree = NULL;
	for (int i = 0; i < n; i++){
		tree_insert(&tree, invec[i]);
	}
	tree_rlr_travel(tree, lvec);
	tree_rrl_travel(tree, rvec);
	if (lvec == invec){
		cout << "YES" << endl;
		tree_lrroot_travel(tree, outvec);
		for (int i = 0; i < n - 1; i++)
			cout << outvec[i] << ' ';
		cout << outvec[n - 1];
	}
	else if(rvec == invec){
		cout << "YES" << endl;
		tree_rlroot_travel(tree, outvec);
		for (int i = 0; i < n - 1; i++)
			cout << outvec[i] << ' ';
		cout << outvec[n - 1];
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}