#include <iostream>
#include <cstring>
#include "BSTree.h"

using namespace std;



int main() {
	BSTree<string> * BSTFCI = new BSTree<string>;
	BSTFCI->add("5");
	BSTFCI->add("3");
	BSTFCI->add("7");
	BSTFCI->add("2");
	BSTFCI->add("4");
	BSTFCI->add("9");
	BSTFCI->add("1");
	BSTFCI->add("8");
	BSTFCI->add("10");

	BSTree<string> * second = new BSTree<string>;
	second->add("3");
	second->add("2");
	second->add("4");
	second->add("1");

	BSTFCI->inorder(BSTFCI->getRoot());

	BSTFCI->printRange("8", "15");

	cout << "\nis Subtree >> " << isSubTree(second, BSTFCI) << endl;

	BSTree<string> * BSTFCI = new BSTree<string>;
	BSTFCI->runTreeApp("AppWords1.txt");

	system("pause");
	return 0;
}