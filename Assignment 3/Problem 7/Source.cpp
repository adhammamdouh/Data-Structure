#include "PriorityQueue.h"
#include <iostream>

using namespace std;

int main() {

	PriorityQueue q;
	q.enqueue("adham", 5);
	q.enqueue("waled", 10);
	q.enqueue("khaled", 7);
	q.enqueue("menna", 8);
	q.enqueue("samer", 4);

	cout << "before deletion" << endl ;
	q.print();

	cout << "\ndelete\n";
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << "\nafter deletion" << endl;
	q.print();

	cout << "\nadd to queue again" << endl;
	q.enqueue("okasha", 15);
	q.enqueue("hello", 3);
	q.enqueue("omar", 9);
	q.print();
	cout << endl;

	system("pause");
	return 0;
}
