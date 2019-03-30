#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
	map<string, int> Words;
	set<string> AErase;
	string Word;
	while (true) {
		cin >> Word;
		if (Word == "done")break;
		Words[Word]++;
		if (Word[0] == 'a' || Word[0] == 'A')AErase.insert(Word);
	}
	cout << "before erasing" << endl;
	for (auto X : Words) {
		cout << X.first << " : " << X.second << endl;
	}

	for (auto X : AErase) {
		Words.erase(X);
	}
	cout << "After erasing" << endl;
	for (auto X : Words) {
		cout << X.first << " : " << X.second << endl;
	}
	system("pause");
}
