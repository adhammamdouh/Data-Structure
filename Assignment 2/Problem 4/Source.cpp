#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Triangle(vector<int> &arr) {
	int SZ = arr.size();
	if (SZ > 3) {
		sort(arr.begin(), arr.end());

		for (int i = 0; i < SZ - 2; ++i) {
			if (arr[i] + arr[i + 1] > arr[i + 2] && arr[i] + arr[i + 2] > arr[i + 1] && arr[i + 1] + arr[i + 2] > arr[i]) {
				cout << "it is non-degenerate triangle" << endl;
				cout << "values : " << arr[i] << " " << arr[i + 1] << " " << arr[i + 2] << endl;
				return;
			}
		}
	}
	cout << "Not a non-degenerate triangle!" << endl;
}


int main() {
	vector<int> arr;
	int n;
	cout << "Enter the size of the arrey : ";
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	Triangle(arr);

	system("pause");
	return 0;
}