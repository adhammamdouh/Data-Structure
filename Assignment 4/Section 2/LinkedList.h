#pragma once
#include <iostream>
#include <string>

using namespace std;

template<class T> class Node;

template<class T>
class LinkedList {
public:
	class Iterator {
	private:
		Node<T>* CurrentNode = new Node<T>;
		friend class LinkedList;
	public:
		Iterator() :CurrentNode(head) {}
		Iterator(Node<T>* pNode) :CurrentNode(pNode) {}

		Iterator& operator =(Node<T>* pNode) 
		{
			this->CurrentNode = pNode;
			return *this;
		}

		Iterator& operator++ () 
		{
			if (CurrentNode == nullptr)throw invalid_argument("invalid position");
			if (CurrentNode)
				CurrentNode = CurrentNode->next;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator iterator = *this;
			++*this;
			return iterator;
		}

		Iterator& operator--()
		{
			if (CurrentNode == nullptr) throw invalid_argument("invalid position");
			if (CurrentNode)
				CurrentNode = CurrentNode->last;
			return *this;
		}

		bool operator ==(const Iterator& iterator)
		{
			return CurrentNode == iterator.CurrentNode;
		}

		bool operator!=(const Iterator& iterator)
		{
			return CurrentNode != iterator.CurrentNode;
		}

		T& operator*()
		{
			if (CurrentNode == nullptr)throw invalid_argument("invalid position");
			return CurrentNode->value;
		}
	};
private:
	Node<T>* head;
	Node<T>* tail;
	int sz;
public:
	LinkedList();
	Node<T>* addSorted(T v);
	Node<T>* get(T v);
	Iterator begin() {
		return Iterator(head);
	}

	Iterator end() {
		return Iterator(nullptr);
	}
	int size(); 

	friend ostream& operator<< <>(ostream& out,LinkedList<T> & obj);
	virtual ~LinkedList();
};

template<typename T>
class Node
{
public:
	T value;
	Node* next;
	Node* last;
	friend class LinkedList<T>;
	Node(T v);
	Node();
};

template<typename T>
inline Node<T>::Node(T v)
{
	this->value = v;
	this->next = nullptr;
	this->last = nullptr;
}

template<typename T>
inline Node<T>::Node()
{
	this->next = nullptr;
	this->last = nullptr;
}

template<class T>
LinkedList<T>::LinkedList()
{
	this->head = nullptr;
	sz = 0;
}

template<class T>
inline Node<T> * LinkedList<T>::addSorted(T v)
{
	Node<T> * temp = new Node<T>;
	temp->next = nullptr;
	temp->last = nullptr;
	temp->value = v;

	if (head == nullptr) {
		head = temp;
		tail = temp;
	}
	else if (v < head->value){
		temp->next = head;
		head->last = temp;
		head = temp;
	}
	else {
		Node<T> * cur = head;
		Node<T> * last = head;
		for (int i = 0; i < this->sz; ++i) {
			if (v < cur->value) {
				last = cur->last;
				
				last->next = temp;
				temp->last = last;
				
				temp->next = cur;
				cur->last = temp;
				sz++;
				return temp;
			}
			else if (v == cur->value) return cur;
			cur = cur->next;
		}
		last = tail;
		tail->next = temp;
		tail = tail->next;
		tail->last = last;
	}
	sz++;
	return temp;
}

template<class T>
inline Node<T> * LinkedList<T>::get(T v)
{
	Node<T> * cur = head;
	for (int i = 0 ; i < this->sz ; ++i)
	{
		if (cur->value = v)return cur;
		cur = cur->next;
	}
	return nullptr;
}

template<class T>
inline int LinkedList<T>::size()
{
	return this->sz;
}

template<typename T>
ostream& operator<< <>(ostream& out,LinkedList<T> & obj){
	Node<T> * cur = obj.head;
	for (int i = 0; i < obj.sz; ++i) {
		out << cur->value << endl;
		cur = cur->next;
	}
	return out;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	Node<T> * current = head;
	while (current != 0) {
		Node<T> * next = current->next;
		delete current;
		current = next;
	}
	head = 0;
}
