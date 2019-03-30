#include "searcher.h"

searcher::searcher()
{
}

void searcher::LoadWords()
{
	fstream WordFile;
	WordFile.open("words.txt", ios::in | ios::out);
	int j = 0;
	while (WordFile.peek() != EOF && j <= 100000)
	{
		string tmp;
		getline(WordFile, tmp);
		Words.push_back(tmp);
		j++;
	}
	WordFile.close();
}

void searcher::FoundSearch(int WordsNum)
{
	int Found = 0, comp = 0;
	high_resolution_clock::time_point start;
	high_resolution_clock::time_point stop;
	microseconds duration{};
	for (int i = 0; i < 100; ++i) {
		comp = 0;
		int random = rand() % (WordsNum);
		start = high_resolution_clock::now();
		binarySearch(0, WordsNum - 1, Words[random], comp);
		stop = high_resolution_clock::now();
		duration += duration_cast<microseconds>(stop - start);
		Found += comp;
		c.push_back(comp);
	}
	cout << "average comparisons for found : ";
	cout << Found / 100 << endl;
	cout << "average time for found : ";
	cout << (duration.count() / 100) << endl;
}

void searcher::NotFoundSearch(int WordsNum)
{
	int comp = 0, NotFound = 0;
	high_resolution_clock::time_point start;
	high_resolution_clock::time_point stop;
	microseconds duration{};
	for (int i = 0; i < 100; ++i) {
		comp = 0;
		string tmp = "";
		for (int i = 0; i < 5; ++i) {
			tmp += (char)(rand() % (90 - 65 + 1)) + 65;
		}
		start = high_resolution_clock::now();
		binarySearch(0, WordsNum - 1, tmp, comp);
		stop = high_resolution_clock::now();
		duration += duration_cast<microseconds>(stop - start);
		NotFound += comp;
		c.push_back(comp);
	}
	cout << "average comparisons for not found : ";
	cout << NotFound / 100 << endl;
	cout << "average time for not found : ";
	cout << (duration.count() / 100) << endl;
}

int searcher::binarySearch(int l, int r, string word, int & comp)
{
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (Words[m] == word)
			return m;
		if (Words[m] < word)
			l = m + 1;
		else
			r = m - 1;
		comp++;
	}
	return -1;
}

void searcher::testPerformance()
{
	fstream Excel;
	Excel.open("GraphFile.csv", ios::out);
	int arr[]{ 10000,20000,30000,50000,100000 };
	for (int i = 0; i < 5; ++i) {
		Excel << "for " << arr[i] << " found" << ',' << "for " << arr[i] << " not Found" ;
		if (i == 4) 
			Excel << endl;
		else
			Excel << ',';
		
		FoundSearch(arr[i]);
		NotFoundSearch(arr[i]);
	}
	
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 10; ++j) {
			Excel << c[100 * j + i];
			if (j == 9)
				Excel << endl;
			else
				Excel << ',';
		}
	}

	Excel.close();
}

searcher::~searcher()
{
}
