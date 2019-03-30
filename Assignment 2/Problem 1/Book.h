#pragma once
#include<iostream>
#include<string>

using namespace std;

class Book
{
private:
	string Name;
	string Author;
	int PublishYear;
	int NumberOfAvail;
public:
	Book();
	void SetAll(string Name, string Author, int PublishYear, int NumberOfAvail);
	void SetName(string Name);
	string GetName();
	
	void SetAuthor(string Author);
	string GetAuthor();

	void SetPublishYear(int PY);
	int GetPublishYear();

	void SetNumberOfAvail(int Avail);
	int GetNumberOfAvail();

	void print();
	virtual ~Book();
};

