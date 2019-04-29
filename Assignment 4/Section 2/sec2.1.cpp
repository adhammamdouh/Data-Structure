#include <iostream>
#include "treap.h"

int main()
{
	treap <string, string> T;
	T.add("002098765", "Bob");
	T.add("002054321", "Mina Zaki");
	T.add("002011111", "Sayed Hassan");
	T.add("002011111", "Sayed Hassan");
	T.add("001011111", "btngan1");
	T.add("003011111", "btngan3");

	T.print();
	
	T.find("002098765");
	T.find("002054321");
	T.find("002054321");
	T.find("012521212");
	T.find("002011111");
	T.find("001011111");
	T.find("003011111");
	ee
	return  0;
}
