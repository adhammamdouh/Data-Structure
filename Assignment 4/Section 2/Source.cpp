#include<iostream>
#include "ContactManager.h"

using namespace std;

int main() {
	ContactManager softWare;
	softWare.loadFromFile("all-contacts.txt");

	system("pause");
	return 0;
}