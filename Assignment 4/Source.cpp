#include <iostream>
#include "BSTree.h"

using namespace std;

int main() {
	BSTree BSTFCI;
	BSTFCI.add(5);
	BSTFCI.add(1);
	BSTFCI.add(0);
	BSTFCI.add(15);
	BSTFCI.add(125);
	BSTFCI.add(5156);
	BSTFCI.add(41);
	BSTFCI.add(12);
	BSTFCI.add(0);
	BSTFCI.add(-1);
	BSTFCI.add(-15);
	BSTFCI.add(125);
	BSTFCI.add(84);

	BSTFCI.inorder(BSTFCI.getRoot());

	system("pause");
	return 0;
}
