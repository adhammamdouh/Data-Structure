#pragma once
#include<iostream>

using namespace std;

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
	int size;
	node * newNode(int value);
	node * addInTree(node * nde, int key);
	node * search(node * cur, int value);
	void printRange(int l, int r, node * _root);
	friend bool Compare(node * node1, node * node2);

public:
	BSTree();
	BSTree(node * n);
	node * getRoot();
	node * add(int value);
	void flip();
	void flip(node * node);
	void inorder(node *root);
	void printRange(int l, int r);
	virtual ~BSTree();

	friend bool isSubTree(BSTree* Tree1, BSTree* Tree2);
};

