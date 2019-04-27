#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

class Contact
{
private:
	string name;
	LinkedList<string> phone_numbers;
public:
	Contact();
	Contact(string name);
	void addPhoneNumber(string number);
	string getName();
	bool operator<(const Contact & c);
	bool operator==(const Contact & c);
	friend ostream& operator<<(ostream& out, Contact & c);
	virtual ~Contact();
};

