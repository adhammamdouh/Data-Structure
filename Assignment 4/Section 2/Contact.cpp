#include "Contact.h"



Contact::Contact()
{
}

Contact::Contact(string name)
{
	this->name = name;
}

void Contact::addPhoneNumber(string number)
{
	phone_numbers.addSorted(number);
}

string Contact::getName()
{
	return name;
}

bool Contact::operator<(const Contact & c)
{
	if (this->name < c.name)return 1;
	return 0;
}

bool Contact::operator==(const Contact & c)
{
	if(this->name == c.name)return 1;
	return 0;
}


Contact::~Contact()
{
}

ostream & operator<<(ostream & out, Contact & c)
{
	out << c.name << " :" << endl;
	out << c.phone_numbers << endl;
	return out;
}
