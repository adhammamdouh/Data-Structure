#include <iostream>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

void start();
void buildVector(int SZ, fstream &Excel);
void InsertionSort(vector<int> &vec);
int upperBound(vector<int> & vec, int L, int R, int key);
void BinaryInsertionSort(vector<int> &vec);

int main() {
	start();
	
	system("pause");
	return 0;
}

void start() {
	fstream Excel;
	Excel.open("GraphFile.csv", ios::out);
	Excel << ',' << "For Binary Search" << ',' << "for sequential" << endl;

	int SIZE[]{ 10,50,100,200,300,400,500,600,700,800,900,1000,1500,2000,2500,3000,3500,4000,4500,5000 };
	for (int i = 0; i < 20; ++i) {
		buildVector(SIZE[i], Excel);
		cout << SIZE[i] <<  " Done" << endl;
	}
}

void buildVector(int SZ,fstream &Excel) {
	vector<int> vecB;
	vector<int> vecS;
	for (int i = 0; i < SZ; ++i) {
		int num = rand();
		vecS.push_back(num);
		vecB.push_back(num);
	}
	auto startB = high_resolution_clock::now();
	BinaryInsertionSort(vecB);
	auto StopB = high_resolution_clock::now();
	auto durationB = duration_cast<microseconds>(StopB - startB);

	auto startS = high_resolution_clock::now();
	InsertionSort(vecS);
	auto StopS = high_resolution_clock::now();
	auto durationS = duration_cast<microseconds>(StopS - startS);

	Excel << "for " << SZ << ',' << durationB.count() << ',' << durationS.count() << endl;
}

void InsertionSort(vector<int> &vec) {
	int SZ = vec.size();
	for (int i = 1; i < SZ; ++i) {

		int j = i;
		while(j > 0 && vec[j-1] > vec[j]) {
			int tmp = vec[j];
			vec[j] = vec[j - 1];
			vec[j - 1] = tmp;
			j--;
		}
	}
}

int upperBound(vector<int> & vec,int L, int R, int key) {
	int l = L, r = R;

	while (l <= r) {
		int mid = (l + r) / 2;

		if (vec[mid] == key) {
			l = mid + 1;
		}
		else if (vec[mid] > key) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	return (l >= vec.size()) ? -1 : l;
}

void BinaryInsertionSort(vector<int> &vec) {
	int SZ = vec.size();
	for (int i = 1; i < SZ; ++i) {
		int index = upperBound(vec, 0, i - 1, vec[i]);
		if (index == -1)continue;
		
		int temp = vec[i];
		for (int k = i; k > index; --k) {
			vec[k] = vec[k - 1];
		}
		vec[index] = temp;
		
	}
}