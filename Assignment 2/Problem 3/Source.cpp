#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>
#include "searcher.h"

using namespace std;

int main() {
	
	searcher search;
	search.LoadWords();
	search.testPerformance();
	
	system("pause");
	return 0;
}