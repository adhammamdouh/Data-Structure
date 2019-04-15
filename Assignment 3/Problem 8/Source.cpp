#include <iostream>
#include <queue>

using namespace  std;

class Stack
{
public:
	Stack();
	int top() {
		return STC.front();
	}
	void push(int value) {
		int sz = STC.size();
		int *temp = new int[sz];
		int i = 0;
		while (!STC.empty())
		{
			int val = STC.front();
			STC.pop();
			temp[i++] = val;
		}
		STC.push(value);
		for (int j = 0; j < sz; ++j) {
			STC.push(temp[j]);
		}
		delete[]temp;
	}
	void pop() {
		STC.pop();
	}
	int size() {
		return STC.size();
	}
	~Stack();

private:
	queue<int> STC;
};

Stack::Stack()
{
}

Stack::~Stack()
{
}

int main() {

	Stack s;
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(8);
	s.push(9);
	s.push(10);
	s.push(11);
	s.push(12);

	while (true) {
		if (s.size() == 0)break;
		cout << s.top() << " ";
		s.pop();
	}cout << endl;


	system("pause");
	return 0;
}
