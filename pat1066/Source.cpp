#include <iostream>
using namespace::std;
inline int max(int a, int b){
	if(a >b)
		return a;
	else
		return b;
}

typedef struct AVLNode
{
	int value;
	struct AVLNode *lchild, *rchild;
}AVLNode;

AVLNode *rotate_LL(AVLNode *parent){//class 用驼峰命名，函数和方法用下划线命名
	AVLNode *child = parent->lchild;
	parent->lchild = child->rchild;
	child->rchild = parent;
	return child;
}

AVLNode *rotate_RR(AVLNode *parent){
	AVLNode *child = parent->rchild;
	parent->rchild = child->lchild;
	child->lchild = parent;
	return child;
}

AVLNode *rotate_LR(AVLNode *parent){
	parent->lchild = rotate_RR(parent->lchild);
	return rotate_LL(parent);
}

AVLNode *rotate_RL(AVLNode *parent){
	parent->rchild = rotate_LL(parent->rchild);
	return rotate_RR(parent);
}

int get_height(AVLNode *root){
	return root == NULL ? 0 : 1 + max(get_height(root->lchild), get_height(root->rchild));
}

int get_balance(AVLNode *root){
	return root == NULL ? 0 : get_height(root->lchild) - get_height(root->rchild);
}

AVLNode *insert_node(AVLNode **root, int value){
	if (*root == NULL){
		*root = new AVLNode;
		(*root)->value = value;
		(*root)->lchild = (*root)->rchild = NULL;
	}
	else if ((*root)->value > value){
		insert_node(&(*root)->lchild, value);
	}
	else{
		insert_node(&(*root)->rchild, value);
	}
	return *root;
}

void print_AVL(AVLNode *root){
	if (root == NULL)
		return;
	cout << root->value << ' ';
	print_AVL(root->lchild);
	print_AVL(root->rchild);
}

bool isbalance(AVLNode *root){
	return get_balance(root) > -2 && get_balance(root) < 2;
}

AVLNode *balance_AVL(AVLNode *root){
	if (get_balance(root) > 1 && isbalance(root->lchild) && isbalance(root->rchild)){//L
		if (get_balance(root->lchild) > 0){//LL
			root = rotate_LL(root);
		}
		else{//LR
			root = rotate_LR(root);
		}
	}

	if (get_balance(root) < -1 && isbalance(root->lchild) && isbalance(root->rchild)){//R
		if (get_balance(root->rchild) < 0){//RR
			root = rotate_RR(root);
		}
		else{//RL
			root = rotate_RL(root);
		}
	}

	if (!isbalance(root->lchild)){
		root->lchild = balance_AVL(root->lchild);
	}
	if (!isbalance(root->rchild)){
		root->rchild = balance_AVL(root->rchild);
	}
	return root;
}

int main(){
	AVLNode *root = NULL;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int v;
		cin >> v;
		insert_node(&root, v);
		root = balance_AVL(root);
	}
	cout << root->value << endl;
}