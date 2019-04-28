#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "_NODE.h"

using namespace std;

template<typename type> class _NODE;
template<typename type> class BSTree;

template<typename type> bool Compare(_NODE<type> * node1, _NODE<type> * node2);
template<typename type> bool isSubTree(BSTree<type>* Tree1, BSTree<type>* Tree2);

template<typename T>
class BSTree
{
private:
	_NODE<T> * root;
	int size;
	_NODE<T> * newNode(T value, int line = -1);
	_NODE<T> * addInTree(_NODE<T> * nde, T key, int line = -1);
	_NODE<T> * search(_NODE<T> * cur, T value);
	void printRange(T l, T r, _NODE<T> * _root);
	int Length(_NODE<T>* n);
	bool isBalance(_NODE<T>* n);
	void printLines(_NODE<T> *root);
	friend bool Compare<>(_NODE<T> * node1, _NODE<T> * node2);

public:
	BSTree();
	BSTree(_NODE<T> * n);
	_NODE<T> * getRoot();
	_NODE<T> * add(T value, int line = -1);
	void flip();
	void flip(_NODE<T> * node);
	void inorder(_NODE<T> *root);
	void printRange(T l, T r);
	bool isBalance();
	void runTreeApp(string fileName);
	virtual ~BSTree();
	
	friend bool isSubTree<>(BSTree<T>* Tree1, BSTree<T>* Tree2);
};

template<typename T>
inline _NODE<T> * BSTree<T>::newNode(T value, int line)
{
	_NODE<T> * temp = new _NODE<T>;
	temp->value = value;
	temp->left = nullptr;
	temp->right = nullptr;
	if (line != -1) temp->lines.push_back(line);
	return temp;
}

template<typename T>
inline _NODE<T> * BSTree<T>::addInTree(_NODE<T> * nde, T key, int line)
{
	if (nde == nullptr) return newNode(key,line);

	if (key < nde->value)
		nde->left = addInTree(nde->left, key, line);
	else if (key > nde->value)
		nde->right = addInTree(nde->right, key, line);
	else
		if (line != -1) nde->lines.push_back(line);
	return nde;
}

template<typename T>
inline _NODE<T> * BSTree<T>::search(_NODE<T> * cur, T value)
{
	if (cur == nullptr)return nullptr;
	else if (value < cur->value)return search(cur->left, value);
	else if (value > cur->value) return search(cur->right, value);
	return cur;
}

template<typename T>
inline void BSTree<T>::printRange(T l, T r, _NODE<T> * _root)
{
	if (_root == nullptr) return;

	if (_root->value < l) {
		printRange(l, r, _root->right);
	}
	else if (_root->value >= l && _root->value <= r)
	{
		printRange(l, r, _root->left);
		cout << _root->value << endl;
		printRange(l, r, _root->right);
	}
	else if (_root->value > r) {
		printRange(l, r, _root->left);
	}

}

template<typename T>
inline int BSTree<T>::Length(_NODE<T>* n) {
	if (n == nullptr)  return -1;

	n->length = max((Length(n->left)) + 1, (Length(n->right)) + 1);

	return n->length;

}

template<typename T>
inline bool BSTree<T>::isBalance(_NODE<T> * n)
{
	if (n->left == nullptr && n->right == nullptr) return 1;

	if (n->left != nullptr && n->right != nullptr) {
		if (abs(n->left->length - n->right->length) > 1) return 0;

		return min(isBalance(n->left), isBalance(n->right));
	}

	else {
		if (n->left != nullptr) return isBalance(n->left);
		else return isBalance(n->right);
	}
}

template<typename T>
inline void BSTree<T>::printLines(_NODE<T> *root)
{
	int sz;
	if (root != nullptr)
	{
		printLines(root->left);
		cout << root->value << " ";
		sz = root->lines.size();
		for (int i = 0; i < sz; ++i) {
			cout << root->lines[i] << " ";
			if (i != sz - 1)cout << ',';
		}
		cout << endl;
		printLines(root->right);
	}
}

template<typename T>
inline BSTree<T>::BSTree()
{
	root = nullptr;
	size = 0;
}

template<typename T>
inline BSTree<T>::BSTree(_NODE<T> * n)
{
	root = newNode(n->value);
	size = 1;
}

template<typename T>
inline _NODE<T> * BSTree<T>::getRoot()
{
	return root;
}

template<typename T>
inline _NODE<T> * BSTree<T>::add(T value, int line)
{
	size++;
	if (root == nullptr) {
		root = this->newNode(value, line);
		return root;
	}
	_NODE<T> * current = root;
	return addInTree(current, value, line);
}

template<typename T>
inline void BSTree<T>::flip()
{
	this->flip(this->root);
}

template<typename T>
inline void BSTree<T>::flip(_NODE<T> * nde)
{
	if (nde == nullptr) return;

	_NODE<T> * temp = nde->left;
	nde->left = nde->right;
	nde->right = temp;
	flip(nde->left);
	flip(nde->right);
}

template<typename T>
inline void BSTree<T>::inorder(_NODE<T> *root)
{
	if (root != nullptr)
	{
		inorder(root->left);
		cout << root->value << endl;
		inorder(root->right);
	}
}

template<typename T>
inline void BSTree<T>::printRange(T l, T r)
{
	printRange(l, r, this->root);
}

template<typename T>
inline bool BSTree<T>::isBalance()
{
	Length(this->root);
	return isBalance(this->root);
}

template<typename T>
inline void BSTree<T>::runTreeApp(string fileName)
{
	fstream appFile;
	appFile.open(fileName, ios::out | ios::in);
	int numlines;
	string word = "";
	char Char = '0';

	appFile >> numlines;
	appFile.get(Char);

	for (int i = 0; i < numlines; ++i) {
		Char = '0';
		while (Char != '\n' && appFile.peek() != EOF)
		{
			appFile.get(Char);
			if (Char == '.' || Char == ',' || Char == '?')continue;
			else if (Char == ' ' || Char == '\n' || Char == '\'') {
				this->add(word, i + 1);
				word = "";
				continue;
			}
			word += Char;
		}
	}
	cout << endl;
	this->printLines(this->root);
}

template<typename T>
inline BSTree<T>::~BSTree()
{
}

template<typename T>
inline bool Compare(_NODE<T> * node1, _NODE<T> * node2)
{
	if (node1 == nullptr && node2 == nullptr)return 1;
	else if (node1 == nullptr && node2 != nullptr) return 0;
	else if (node1 != nullptr && node2 == nullptr)return 0;
	if (node1->value == node2->value)
		return 1 * Compare(node1->left, node2->left) * Compare(node1->right, node2->right);
	else
		return 0;
}

template<typename T>
inline bool isSubTree(BSTree<T> * Tree1, BSTree<T> * Tree2)
{
	if (Tree1 == nullptr || Tree2 == nullptr)return 0;
	if (Tree2->size > Tree1->size) {
		BSTree<T> * temp = Tree2;
		Tree2 = Tree1;
		Tree1 = temp;
	}
	_NODE<T> * temp = Tree1->root;
	_NODE<T> * root2 = Tree2->root;

	_NODE<T> * nde = Tree1->search(temp, root2->value);
	if (nde == nullptr)return 0;

	if (Compare(nde, root2))return 1;
	return 0;
}