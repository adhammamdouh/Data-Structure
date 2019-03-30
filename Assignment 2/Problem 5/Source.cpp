#include <iostream>
#include <chrono>
#include <vector>
#include <stdlib.h>
#include <fstream>

using namespace std;
using namespace std::chrono;

void start();
void BuildVector(int SZ, fstream &Excel);
void TryVector(vector<int>& vecQ, vector<int> vecM, int SZ, fstream & Excel);
void QuickSort(vector<int>& vec, int L, int R);
void MergeSort(vector<int>& vec, int l, int r);
void Merge(vector<int>& vec, int l, int m, int r);

int main() {
	start();
	
	system("pause");
	return 0;
}

void start() {
	fstream Excel;
	Excel.open("GraphFile.csv", ios::out);

	Excel << ',' << "Quick Sort" << ',' << "Merge Sort" << endl;

	int arr[11]{ 5000,10000,20000,30000,40000,50000,60000,70000,80000,90000,100000 };
	for (int i = 0; i < 11; ++i) {
		BuildVector(arr[i], Excel);
		cout << arr[i] << " Done" << endl;
	}

	Excel.flush();
	Excel.close();
}

void BuildVector(int SZ, fstream &Excel) {
	vector<int> vecQ;
	vector<int> vecM;
	for (int i = 0; i < SZ; ++i) {
		int num = rand();
		vecM.push_back(num);
		vecQ.push_back(num);
	}
	TryVector(vecQ, vecM, SZ, Excel);
}

void TryVector(vector<int>& vecQ, vector<int> vecM, int SZ, fstream & Excel) {
	auto startQ = high_resolution_clock::now();
	QuickSort(vecQ, 0, SZ - 1);
	auto stopQ = high_resolution_clock::now();
	auto durationQ = duration_cast<microseconds>(stopQ - startQ);

	auto startM = high_resolution_clock::now();
	MergeSort(vecM, 0, SZ - 1);
	auto stopM = high_resolution_clock::now();
	auto durationM = duration_cast<microseconds>(stopM - startM);

	Excel << "for " << SZ << ',' << durationQ.count() << ',' << durationM.count() << endl;
}

void QuickSort(vector<int>& vec, int L, int R) {
	int i = L;
	int j = R;
	int Mid = (L + R) / 2;
	while (i <= j)
	{
		while (vec[i] < vec[Mid]) {
			i++;
		}
		while (vec[j] > vec[Mid]) {
			--j;
		}
		if (i <= j) {
			int temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
			j--;
			i++;
		}
	}
	if (L < j)
		QuickSort(vec, L, j);
	if (i < R)
		QuickSort(vec, i, R);
}

void MergeSort(vector<int>& vec, int l, int r){
	if (l < r)
	{
		int m = l + (r - l) / 2;
		MergeSort(vec, l, m);
		MergeSort(vec, m + 1, r);
		Merge(vec, l, m, r);
	}
}

void Merge(vector<int>& vec, int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	vector<int> L(n1);
	vector<int> R(n2);

	for (i = 0; i < n1; i++)
		L[i] = vec[l + i];
	for (j = 0; j < n2; j++)
		R[j] = vec[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			vec[k] = L[i];
			i++;
		}
		else
		{
			vec[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		vec[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		vec[k] = R[j];
		j++;
		k++;
	}
}