#pragma once
#include "Book.h"
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class Library
{
private:
	map<string, Book> _BOOKS;
public:
	Library();
	void AddBook(string Name, string Author, int PublishYear, int NumberOfAvail);
	void SearchByName(string Name);
	void SearchByAuthor(string Author);
	void UpdateNumOfAvail(string Name, int Avail);
	void HighestBook();
	void Print();
	virtual ~Library();
};

