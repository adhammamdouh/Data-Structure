#include "ContactManager.h"

ContactManager::ContactManager()
{
}

bool ContactManager::loadFromFile(string fileName)
{
	fstream contactFile;
	contactFile.open(fileName, ios::out | ios::in);
	if (contactFile.fail())return 0;
	string name, phoneNumber;
	
	while (contactFile.peek() != EOF && !contactFile.eof() && !contactFile.fail())
	{
		contactFile >> name;
		getline(contactFile,phoneNumber);
		cout << name << " " << phoneNumber << endl;
		this->add(name, phoneNumber);
	}
}

void ContactManager::add(string name, string phone_number)
{
	Contact temp(name);
	LinkedList<Contact>::Iterator it = contacts.begin();
	
	//should do it using Treap
	for (it; it != contacts.end(); ++it) {
		if ((*it).getName() == name) {
			(*it).addPhoneNumber(phone_number);
			return;
		}
	}
	//end should

	(contacts.addSorted(name))->value.addPhoneNumber(phone_number);
}

void ContactManager::displayNumber(string phone_number)
{
	//TODO: search in Treap and display the name of the contact 
	//if not found
	//display the number itself
}

ContactManager::~ContactManager()
{
}

ostream & operator<<(ostream & out, ContactManager & c)
{
	for (LinkedList<Contact>::Iterator it = c.contacts.begin(); it != c.contacts.end(); ++it) {
		out << (*it) << endl;
	}
	return out;
}
