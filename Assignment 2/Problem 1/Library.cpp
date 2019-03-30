#include "Library.h"



Library::Library()
{
}

void Library::AddBook(string Name, string Author, int PublishYear, int NumberOfAvail)
{
	_BOOKS[Name].SetAll(Name, Author, PublishYear, NumberOfAvail);
}

void Library::SearchByName(string Name)
{
	Book book = _BOOKS[Name];
	if (book.GetNumberOfAvail() != 0) book.print();
}

void Library::SearchByAuthor(string Author)
{
	for (auto X : _BOOKS) {
		if (X.second.GetAuthor() == Author) {
			X.second.print();
			return;
		}
	}
	cout << "Not Exist" << endl;
}

void Library::UpdateNumOfAvail(string Name, int Avail)
{
	_BOOKS[Name].SetNumberOfAvail(Avail);
}

void Library::HighestBook()
{
	int mx = INT_MIN;
	Book book;
	for (auto X : _BOOKS) {
		if (X.second.GetNumberOfAvail() > mx) {
			mx = X.second.GetNumberOfAvail();
			book = X.second;
		}
	}
	book.print();
}

void Library::Print()
{
	for (auto X : _BOOKS) {
		X.second.print();
		cout << endl;
	}
}


Library::~Library()
{
}
