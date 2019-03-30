#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <chrono> 
#include <algorithm> 

using namespace std;
using namespace std::chrono;


class searcher
{
private:
	vector<string> Words;
	vector<int> c;
	int binarySearch(int l, int r, string word, int& comp);

public:
	searcher();
	void LoadWords();
	void FoundSearch(int WordsNum);
	void NotFoundSearch(int WordsNum);
	void testPerformance();
	~searcher();
};

