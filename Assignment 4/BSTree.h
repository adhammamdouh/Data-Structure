#pragma once
#include<stdio.h> 

struct node
{
	int value;
	node * left;
	node * right;
};

class BSTree
{
private:
	node * root;
	node * newNode(int value);
	node * addInTree(node * nde, int key);
public:
	BSTree();
	BSTree(node * n);
	node * getRoot();
	node * add(int value);
	void inorder(node *root);
	virtual ~BSTree();
};

