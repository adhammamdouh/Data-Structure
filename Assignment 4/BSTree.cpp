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

BSTree::BSTree()
{
	root = nullptr;
}

BSTree::BSTree(node * n)
{
	root = new node;
	root->value = n->value;
	root->left = nullptr;
	root->right = nullptr;
}

node * BSTree::getRoot()
{
	return root;
}

node * BSTree::add(int value)
{
	if (root == nullptr) {
		root = this->newNode(value);
		return root;
	}
	node * current = root;
	return addInTree(current, value);
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

BSTree::~BSTree()
{
}
