#pragma once
#include "BSTree.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T> class BSTree;
template<typename T> class _NODE;

template<typename type> bool Compare(_NODE<type> * node1, _NODE<type> * node2);
template<typename type> bool isSubTree(BSTree<type>* Tree1, BSTree<type>* Tree2);

template<typename T>
class _NODE
{
private:
	T value;
	_NODE<T> * left;
	_NODE<T> * right;
	vector<int> lines;
	friend bool Compare<>(_NODE<T> * node1, _NODE<T> * node2);
	friend bool isSubTree<>(BSTree<T>* Tree1, BSTree<T>* Tree2);
	

public:
	_NODE();
	friend class BSTree<T>;
	virtual ~_NODE();
};

template<typename T>
inline _NODE<T>::_NODE()
{
}

template<typename T>
inline _NODE<T>::~_NODE()
{
}
