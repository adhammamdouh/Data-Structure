#pragma once
#include<stdio.h>
#include <iostream>
#include<cmath>

using namespace std;
#define ee cout<<endl;
struct node
{
	int value;
	node * left=nullptr;
	node * right=nullptr;
	int length;
};

class BSTree
{
private:
	node * root=nullptr;
	int size;
	node * newNode(int value);
	node * addInTree(node * nde, int key);
	node * search(node * cur, int value);
	void printRange(int l, int r, node * _root);
	int Length(node* n1);
	bool isBalance(node* n1);
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

	bool isBalance();
	friend bool isSubTree(BSTree* Tree1, BSTree* Tree2);
};

