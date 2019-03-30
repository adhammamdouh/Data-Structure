#include "Book.h"

Book::Book()
{
	this->Name = "";
	this->Author = "";
	this->PublishYear = 0;
	this->NumberOfAvail = 0;
}

void Book::SetAll(string Name, string Author, int PublishYear, int NumberOfAvail)
{
	this->Name = Name;
	this->Author = Author;
	this->PublishYear = PublishYear;
	this->NumberOfAvail = NumberOfAvail;
}

void Book::SetName(string Name)
{
	this->Name = Name;
}

string Book::GetName()
{
	return this->Name;
}

void Book::SetAuthor(string Author)
{
	this->Author = Author;
}

string Book::GetAuthor()
{
	return this->Author;
}

void Book::SetPublishYear(int PY)
{
	this->PublishYear = PY;
}

int Book::GetPublishYear()
{
	return this->PublishYear;
}

void Book::SetNumberOfAvail(int Avail)
{
	this->NumberOfAvail = (Avail <= 0) ? -1 : Avail;
}

int Book::GetNumberOfAvail()
{
	return this->NumberOfAvail;
}

void Book::print()
{
	cout << "Book Name : " << this->Name << endl;
	cout << "Book Author : " <<this->Author << endl;
	cout << "Book Publish Year : " << this->PublishYear << endl;
	cout << "Book number Of Available : " << ((this->NumberOfAvail == -1)? 0:this->NumberOfAvail) << endl;
}

Book::~Book()
{
}
