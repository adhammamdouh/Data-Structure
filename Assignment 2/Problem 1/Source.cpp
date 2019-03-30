#include <iostream>
#include "Library.h"

using namespace std;

void Menu();
void Start();

int main() {
	Start();
	system("pause");
	return 0;
}

void Menu() {
	cout << "1 >> Add Book\n"
		<< "2 >> Search by Name\n"
		<< "3 >> Search by Author\n"
		<< "4 >> List books\n"
		<< "5 >> Update Available Number of Versions\n"
		<< "6 >> book with Highest Number of Versions\n"
		<< "7 >> Display Menu\n"
		<< "8 >> Exit\n";
}

void Start() {
	Library FCI;
	Menu();
	while (true)
	{
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
			case 1: {
				cout << "Enter the book information" << endl;
				cout << "The Name : ";
				string Name; cin >> Name;
				cout << "The Author : ";
				string Author; cin >> Author;
				cout << "Publish Year : ";
				int PY; cin >> PY;
				cout << "Number Of Versions : ";
				int Avail; cin >> Avail;
				FCI.AddBook(Name, Author, PY, Avail);
				break;
			}
			case 2: {
				cout << "Enter the Name : ";
				string Name; cin >> Name;
				FCI.SearchByName(Name);
				break;
			}
			case 3: {
				cout << "Enter the Author : ";
				string Author; cin >> Author;
				FCI.SearchByAuthor(Author);
				break;
			}
			case 4: {
				FCI.Print();
				break;
			}
			case 5: {
				cout << "Enter the Book Name : ";
				string Name; cin >> Name;
				cout << "Enter the Available number of versions : ";
				int Avail; cin >> Avail;
				FCI.UpdateNumOfAvail(Name, Avail);
				break;
			}
			case 6: {
				FCI.HighestBook();
				break;
			}
			case 7: {
				Menu();
				break;
			}
			case 8: {
				return;
				break;
			}
		}
	}
}
