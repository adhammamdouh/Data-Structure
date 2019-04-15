#include "PriorityQueue.h"

PriorityQueue::PriorityQueue()
{
	head = NULL;
	sz = 0;
}

string PriorityQueue::enqueue(string value, int pri)
{
	sz++;
	priority *temp = new priority;
	priority *pre = new priority;
	priority *cur = new priority;
	temp->data = value;
	temp->Priorty = pri;
	temp->next = NULL;

	if (head == NULL || head->Priorty < pri) {
		temp->next = head;
		head = temp;
		return head->data;
	}
	cur = head;
	for (int i = 0; i < sz; ++i) {
		pre = cur;
		cur = cur->next;
		if (cur == NULL || cur->Priorty < pri)break;
	}
	temp->next = cur;
	pre->next = temp;

	return temp->data;
}

void PriorityQueue::print() {
	priority *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}

string PriorityQueue::dequeue()
{
	sz--;
	priority *temp = head;
	string str = head->data;

	head = head->next;
	
	delete temp;
	return str;
}


PriorityQueue::~PriorityQueue()
{
}
