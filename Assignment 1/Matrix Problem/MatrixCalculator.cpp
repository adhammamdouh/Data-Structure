#include "MatrixCalculator.h"
#include "Matrix.h"
#include <iostream>

using namespace std;

MatrixCalculator::MatrixCalculator()
{
}

int MatrixCalculator::menu()
{
	cout << "ahlan ya user ya habiby\n" << endl;
	cout << "Welcome to Adham/Okasha Calculator\n" << endl;
	cout << "What Do you want to do today\n" <<
		"1 >> Perform Matrix Addition\n" <<
		"2 >> Perform Matrix Substraction\n" <<
		"3 >> Perform Matrix Multiplication\n" <<
		"4 >> Matrix TransPose\n" <<
		"5 >> View the Menu\n" <<
		"6 >> Exit the Program\n";
	
	while (true) {
		short Choice;
		int loop = 0;
		cin >> Choice;
		
		if (Choice == 1) {
			cout << "How many matrix you will Enter : ";
			cin >> loop;
			Matrix<double> Obj;
			cin >> Obj;
			for (int i = 1; i < loop; ++i) {
				Matrix<double> tmp;
				cin >> tmp;
				Obj = Obj + tmp;
			}
			cout << Obj;
		}
		else if (Choice == 2) {
			cout << "How many matrix you will Enter : ";
			cin >> loop;
			Matrix<double> Obj;
			cin >> Obj;
			for (int i = 1; i < loop; ++i) {
				Matrix<double> tmp;
				cin >> tmp;
				Obj = Obj - tmp;
			}
			cout << Obj;
		}
		else if (Choice == 3) {
			cout << "How many matrix you will Enter : ";
			cin >> loop;
			Matrix<double> Obj;
			cin >> Obj;
			for (int i = 1; i < loop; ++i) {
				Matrix<double> tmp;
				cin >> tmp;
				Obj = Obj + tmp;
			}
			cout << Obj;
		}
		else if (Choice == 4) {

			Matrix<double> Obj;
			cin >> Obj;
			cout << Obj.Transpose();
		}
		else if (Choice == 5) {
			cout << "1 >> Perform Matrix Addition\n" <<
				"2 >> Perform Matrix Substraction\n" <<
				"3 >> Perform Matrix Multiplication\n" <<
				"4 >> Matrix TransPose\n" <<
				"5 >> View the Menu\n" <<
				"6 >> Exit the Program\n";
		}
		else if (Choice == 6) return 0;
	}
}


MatrixCalculator::~MatrixCalculator()
{
}
