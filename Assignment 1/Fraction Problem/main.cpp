#include<iostream>
#include "Fraction.h"

using namespace std;

int main() {
	Fraction f1 , f2(1);
	cin >> f1;
	
	cout << f1 + f2;
	cout << f1 - f2;
	cout << f1 * f2;
	cout << f1 / f2;

	f1 += f2;
	cout << f1;
	f1 *= f2;
	cout << f1;
	f1 -= f2;
	cout << f1;
	f1 /= f2;
	cout << f1;

	system("pause");
	return 0;
}
