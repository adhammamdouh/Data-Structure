#include "BSTree.h"



node * BSTree::newNode(int value)
{
	node * temp = new node;
	temp->value = value;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}

node * BSTree::addInTree(node * nde, int key)
{
	if (nde == nullptr) return newNode(key);
	
	if (key < nde->value) 
		nde->left = addInTree(nde->left, key);
	else if (key > nde->value)
		nde->right = addInTree(nde->right, key);
	return nde;
}

node * BSTree::search(node * cur, int value)
{
	if (cur == nullptr)return nullptr;
	else if (value < cur->value)return search(cur->left, value);
	else if (value > cur->value) return search(cur->right, value);
	return cur;
}

BSTree::BSTree()
{
	root = nullptr;
	size = 0;
}

BSTree::BSTree(node * n)
{
	root = new node;
	root->value = n->value;
	root->left = nullptr;
	root->right = nullptr;
	size = 1;
}

node * BSTree::getRoot()
{
	return root;
}

node * BSTree::add(int value)
{
	size++;
	if (root == nullptr) {
		root = this->newNode(value);
		return root;
	}
	node * current = root;
	return addInTree(current, value);
}

void BSTree::flip()
{
	this->flip(this->root);
}

void BSTree::flip(node * nde)
{
	if (nde == nullptr) return;

	node * temp = nde->left;
	nde->left = nde->right;
	nde->right = temp;
	flip(nde->left);
	flip(nde->right);
}

void BSTree::inorder(node *root)
{
	if (root != nullptr)
	{
		inorder(root->left);
		printf("%d \n", root->value);
		inorder(root->right);
	}
}

void BSTree::printRange(node * root, int l, int r)
{
	if (root == nullptr) return;
	
	if (root->value < l) {
		printRange(root->right, l, r);
	}
	else if (root->value >= l && root->value <= r)
	{
		printRange(root->left, l, r);
		cout << root->value << endl;
		printRange(root->right, l, r);
	}
	else if (root->value > r) {
		printRange(root->left, l, r);
	}
	
}

BSTree::~BSTree()
{
}

bool Compare(node * node1, node * node2)
{
	if (node1 == nullptr && node2 == nullptr)return 1;
	else if (node1 == nullptr && node2 != nullptr) return 0;
	else if (node1 != nullptr && node2 == nullptr)return 0;
	if (node1->value == node2->value)
		return 1 * Compare(node1->left, node2->left) * Compare(node1->right, node2->right);
	else
		return 0;
}

bool isSubTree(BSTree * Tree1, BSTree * Tree2)
{
	if (Tree1 == nullptr || Tree2 == nullptr)return 0;
	if (Tree2->size > Tree1->size) {
		BSTree * temp = Tree2;
		Tree2 = Tree1;
		Tree1 = temp;
	}
	node * temp = Tree1->root;
	node * root2 = Tree2->root;

	node * nde = Tree1->search(temp, root2->value);
	if (nde == nullptr)return 0;

	if (Compare(nde, root2))return 1;
	return 0;
}
