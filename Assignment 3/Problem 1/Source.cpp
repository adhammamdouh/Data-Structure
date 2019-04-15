#include <iostream> 

using namespace std;
 
template<typename T>
struct Node {
	T value;
	Node* next;
	Node* last;
};

template <typename T>
class LinkedList{ 
private:
	Node<T> *head;
	Node<T> *tail;
	int sz;

public:
	LinkedList() { sz = 0; }
	LinkedList(LinkedList<T> const& rhs)
	{
		sz = 0;
		Node<T> *temp = new Node<T>;
		temp = rhs.head;
		for (int i = 0; i < rhs.sz; ++i) {
			this->push_back(temp->value);
			temp = temp->next;
		}
	}

	class Iterator;

	Iterator begin()const
	{
		return Iterator(head);
	}

	Iterator end()const
	{
		return Iterator(nullptr);
	}

	int size() {
		return sz;
	}

	void push_back(T data);
	void insert(T value, int pos);
	void insert(T value, Iterator& pos);

	LinkedList<T>& operator =(const LinkedList<T>& rhs) {
		Node<T> *temp = new Node<T>;
		temp = rhs.head;
		for (int i = 0; i < rhs.sz; ++i) {
			this->push_back(temp->value);
			temp = temp->next;
		}
		return *this;
	}

	Iterator erase(int pos) {
		if (pos < 1 || pos > sz + 1) throw invalid_argument("Invalied position!");

		Node<T> *pre = new Node<T>;
		Node<T> *cur = new Node<T>;
		cur = head;
		for (int i = 1; i < pos; i++)
		{
			pre = cur;
			cur = cur->next;
		}
		pre->next = cur->next;
		
		sz--;
		return Iterator(pre->next);
	}
	class Iterator {
	private:
		Node<T>* CurrentNode;
		friend class LinkedList;

	public:
		Iterator() :CurrentNode(head) { }

		Iterator(Node<T>* pNode) :CurrentNode(pNode) { }

		Iterator& operator =(Node<T>* pNode)
		{
			this->CurrentNode = pNode;
			return *this;
		}

		Iterator& operator++()
		{
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
			if (CurrentNode->last == NULL) throw invalid_argument("hello");
			else
				CurrentNode = CurrentNode->last;
			return *this;
		}

		bool operator ==(const Iterator& iterator)
		{
			return CurrentNode != iterator.CurrentNode;
		}

		bool operator!=(const Iterator& iterator)
		{
			return CurrentNode != iterator.CurrentNode;
		}

		T& operator*()
		{
			return CurrentNode->value;
		}
	};

	virtual ~LinkedList() {
		Node<T> * current = head;
		while (current != 0) {
			Node<T> * next = current->next;
			delete current;
			current = next;
		}
		head = 0;
	}
};

template <typename T>
void LinkedList<T>::push_back(T data)
{
	Node<T> * temp = new Node<T>;
	temp->next = NULL;
	temp->last = NULL;
	temp->value = data;

	if (head == NULL){
		head = temp;
		tail = temp;
	}
	else{
		Node<T> * last = tail;
		tail->next = temp;
		tail = tail->next;
		tail->last = last;
	}
	sz++;
}

template<typename T>
void LinkedList<T>::insert(T value, int pos) {
	if (pos < 1 || pos > sz + 1) throw invalid_argument("Invalied position!");

	Node<T> * pre = new Node<T>;
	Node<T> * cur = new Node<T>;
	Node<T> * temp = new Node<T>;
	cur = head;
	for (int i = 1; i < pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	temp->value = value;
	pre->next = temp;
	temp->next = cur;
}

int main()
{
	LinkedList<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	//list->insert(5, 5);

	for (LinkedList<int>::Iterator iterator = list.begin(); iterator != list.end(); iterator++){
		cout << *iterator << " ";
	}
	cout << endl;
	LinkedList<int>::Iterator t = list.begin();
	cout << *t++ << endl;
	cout << *t++ << endl;
	cout << *--t << endl;

	LinkedList<int> copyList;
	copyList = list;
	copyList.insert(5, 2);
	list.push_back(10);
	for (LinkedList<int>::Iterator iterator = copyList.begin(); iterator != copyList.end(); iterator++){
		cout << *iterator << " ";
	}cout << endl;

	for (LinkedList<int>::Iterator iterator = list.begin(); iterator != list.end(); iterator++) {
		cout << *iterator << " ";
	}

	cout << endl;
	system("pause");
	return 0;
}
