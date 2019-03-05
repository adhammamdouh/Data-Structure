#pragma once
#include <iostream>

class Fraction
{
private:
	int Num;
	int Denom;
	void Reduce();
	int GCD(int a, int b);
public:
	Fraction();
	Fraction(int num);
	Fraction(int Num, int Denom);
	Fraction(const Fraction& obj);

	Fraction operator-(Fraction& Other);
	Fraction operator+ (Fraction& Other);
	Fraction operator*(Fraction& Other);
	Fraction operator/(Fraction& Other);
	Fraction& operator+=(Fraction& Other);
	Fraction& operator-=(Fraction& Other);
	Fraction& operator*=(Fraction& Other);
	Fraction& operator/=(Fraction& Other);
	Fraction& operator=(Fraction& Other);
	bool operator<(Fraction& Other);
	bool operator>(Fraction& Other);
	bool operator==(Fraction& Other);
	bool operator<=(Fraction& Other);
	bool operator>=(Fraction& Other);

	friend std::istream& operator>>(std::istream& in , Fraction& Obj);
	friend std::ostream& operator<<(std::ostream& out, Fraction& Obj);
	virtual ~Fraction();
};

