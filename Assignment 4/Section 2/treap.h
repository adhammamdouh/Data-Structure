#pragma once
#include <iostream>
#include <string>
#include<cmath>
#include<algorithm>
#include <random>
using namespace std;
#define ee cout<<'\n';

extern int arr[100];
template <class K, class V>
class node {
	template <typename T, typename S>
	friend class treap;
	node* right = nullptr, * left = nullptr;
	K key;
	V val;
	int prior;

public:
	node() {}
	node(K t, V r):key(t),val(r) {
	}
	~node() {}
	
	node<K, V>* operator=(node<K, V>* nde) {
		this = nde;
		this->key = nde->key;
		this->val = nde->val;
		this->left = nde->left;
		this->right = nde->right;
		return this;
	}
	friend ostream& operator<<(ostream& out, node<K, V> &nde);
};


template <class K, class V>
class treap
{
	node<K, V>* root = nullptr;

	void find(node<K, V>* nde, K key);
	node<K,V>* insert(node<K, V>* lst, node<K, V>* nde);


public:
	treap();
	void add(K key, V val);
	void find(K key);
	node<K, V>* rotateRight(node<K, V>* nde);
	node<K, V>* rotateLeft(node<K, V>* nde);
	int makePrior();

	void print(node<K,V>* nde);
	void print();
};




//.......................................................................


template<class K, class V>
int treap<K, V>::makePrior() {
	int r = rand()%100 +1;
	return r;
}

template <class T,class V>
ostream& operator<<(ostream& out, node<T, V>& nde) {
	out << " val " << nde->val;
	ee
	out << " key " << nde->key;
	ee
	out << " prior " << nde->prior;
	ee
	return out;
}

template <class K, class V>
treap<K, V>::treap() {

}

template <class K, class V>
node<K,V>* treap<K, V>::insert(node<K, V>* lst, node<K, V>* nde) {
		if (lst != nullptr && lst->key == nde->key) return lst;
		if (lst == nullptr) {
			lst = nde;
			return lst;
		}
		else if (lst->key > nde->key) {
			lst->left = insert(lst->left, nde);
			if (lst->left->prior > lst->prior) 
				lst = rotateRight(lst);
			
		}

		else {
			lst->right = insert(lst->right, nde);
			if (lst->right->prior < lst->prior)
				lst = rotateLeft(lst);
		}
	return lst;
}

template <class K, class V>
void treap<K, V>::add(K key, V val) {
	node<K, V>* nde= new node<K,V>(key, val);
	nde->prior = makePrior();
	if (root == nullptr) {
		root = nde;
		return;
	}
	insert(root, nde);
}

template <class K, class V>
void treap<K, V>::find(node<K, V>* nde, K key) {
	if (nde == nullptr) {
		cout << key;
		ee
		return;
	}
	else if (nde->key == key) {
		cout << nde->val;
		ee;
		return;
	}
	else {
		if (nde->key > key) {
			return find(nde->left, key);
		}
		else 
			return find(nde->right, key);
		
	}

}

template <class K, class V>
void treap<K, V>::find(K key) {
	find(root, key);
}

template<class K, class V>
node<K, V>* treap<K, V>::rotateRight(node<K, V>* nde) {
	node<K, V>* tmp = new node<K, V>;
	node<K, V>* tmp2 = new node<K, V>;
	tmp = nde->left;
	tmp2 = tmp->right;

	tmp->right = nde;
	nde->left = tmp2;
	if (root == nde) root = tmp;
	return tmp;
}

template<class K, class V>
node<K, V>* treap<K, V>::rotateLeft(node<K, V>* nde) {
	node<K, V>* tmp = new node<K, V>;
	node<K, V>* tmp2 = new node<K, V>;

	tmp = nde->right;
	tmp2 = tmp->left;

	tmp->left = nde;
	nde->right = tmp2;
	if (root == nde) root = tmp;
	return tmp;
}

template<class K, class V>
void treap<K, V>::print(node<K,V>* nde) {
		cout << " prior " << nde->prior;
	ee
		cout << " key " << nde->key;
	ee
		cout << " val " << nde->val;
	ee
	ee

	if (nde->left != nullptr) {
		cout << "on "<<nde->val<<" left \n";
		print(nde->left);
	}
	if (nde->right != nullptr) {
		cout << "on "<<nde->val<<" right \n";
		print(nde->right);
	}
}

template<class K,class V>
void treap<K, V>::print() {
	cout << " Data is ... \n";
	print(this->root);
}