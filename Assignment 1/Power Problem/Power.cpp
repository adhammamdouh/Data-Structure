#include<iostream>

using namespace std;

long long PowerN(long long a, long long n) {
	if (n == 1)return a;
	return a * PowerN(a, n - 1);
}

long long PowerN2(long long a, long long n) {
	if (n == 1)return 2;
	if (n % 2 == 1) {
		n++;
		return (PowerN2(a, n / 2)*PowerN2(a, n / 2))/a;
	}
	return PowerN2(a, n / 2)*PowerN2(a, n / 2);
}

int main() {

	cout << PowerN(2, 5) << endl;
	cout << PowerN2(2, 4) << endl;

	system("pause");
	return 0;
}
