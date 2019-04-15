#pragma once
#include <iostream>
#include <string>


using namespace std;

struct priority {
	string data = "";
	int Priorty;
	priority* next = NULL;
};
class PriorityQueue
{
	priority *head;
	int sz;
public:
	PriorityQueue();

	string enqueue(string value, int pri);
	void print();
	string dequeue();

	virtual ~PriorityQueue();
};

