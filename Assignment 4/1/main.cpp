#include <bits/stdc++.h>
#include "BSTree.h"

using namespace std;

int main() {
	BSTree * BSTFCI = new BSTree;
	BSTFCI->add(5);
	BSTFCI->add(3);
	BSTFCI->add(7);
	BSTFCI->add(2);
	BSTFCI->add(4);
	BSTFCI->add(9);
	BSTFCI->add(1);
	BSTFCI->add(8);
	BSTFCI->add(10);
	BSTFCI->add(0);
//	BSTFCI->add(13);


	BSTree * second = new BSTree;
	second->add(3);
	second->add(2);
	second->add(4);
	second->add(1);

	BSTFCI->printRange(8, 15);

	cout << "\nis Subtree >> " << isSubTree(second, BSTFCI) << endl;

    if(BSTFCI->isBalance()) cout<<"RERERERER";

//	system("pause");
	return 0;
}
