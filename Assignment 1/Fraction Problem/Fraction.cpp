#include "Fraction.h"
#include <cmath>
#include <iostream>
#include <algorithm>  


Fraction::Fraction()
{
	this->Num = 1;
	this->Denom = 1;
}

Fraction::Fraction(int num) {
	this->Num = num;
	this->Denom = 1;
}

Fraction::Fraction(int Num, int Denom) {
	this->Num = Num;
	if(Num == 0)
		this->Denom = 1;
	else
		this->Denom = (Denom == 0) ? 1 : 0;
	Reduce();
}

Fraction::Fraction(const Fraction& Obj) {
	this->Denom = Obj.Denom;
	this->Num = Obj.Num;
}

Fraction Fraction::operator-(Fraction& Other) {
	Fraction tmp;
	tmp.Num = ((this->Num*Other.Denom) - (Other.Num * this->Denom));
	tmp.Denom = (this->Denom * Other.Denom);
	return tmp;
}

Fraction Fraction::operator+ (Fraction& Other) {
	Fraction tmp;
	tmp.Num = ((this->Num*Other.Denom) + (Other.Num * this->Denom));
	tmp.Denom = (this->Denom * Other.Denom);
	return tmp;
}

Fraction Fraction::operator*(Fraction& Other) {
	Fraction tmp;
	tmp.Num = (this->Num * Other.Num);
	tmp.Denom = (this->Denom * Other.Denom);
	return tmp;
}

Fraction Fraction::operator/(Fraction& Other) {
	Fraction tmp;
	tmp.Num = (this->Num * Other.Denom);
	tmp.Denom = (this->Denom * Other.Num);
	return tmp;
}

Fraction& Fraction::operator+=(Fraction& Other) {
	this->Num = ((this->Num*Other.Denom) + (Other.Num * this->Denom));
	this->Denom = (this->Denom * Other.Denom);
	return *this;
}

Fraction& Fraction::operator-=(Fraction& Other) {
	this->Num = ((this->Num*Other.Denom) - (Other.Num * this->Denom));
	this->Denom = (this->Denom * Other.Denom);
	return *this;
}

Fraction& Fraction::operator*=(Fraction& Other) {
	this->Num = (this->Num * Other.Num);
	this->Denom = (this->Denom * Other.Denom);
	return *this;
}

Fraction& Fraction::operator/=(Fraction& Other) {
	this->Num = (this->Num * Other.Denom);
	this->Denom = (this->Denom * Other.Num);
	return *this;
}

Fraction& Fraction::operator=(Fraction& Other) {
	this->Num = Other.Num;
	this->Denom = Other.Denom;
	return *this;
}

bool Fraction::operator<(Fraction& Other) {
	if ((this->Num / this->Denom) < (Other.Num / Other.Denom)) return 1;
	return 0;
}

bool Fraction::operator>(Fraction& Other) {
	if ((this->Num / this->Denom) > (Other.Num / Other.Denom)) return 1;
	return 0;
}

bool Fraction::operator==(Fraction& Other) {
	if ((this->Num == Other.Num) && (this->Denom == Other.Denom)) return 1;
	return 0;
}

bool Fraction::operator<=(Fraction& Other) {
	if (*this < Other || *this == Other) return 1;
	return 0;
}

bool Fraction::operator>=(Fraction& Other) {
	if (*this > Other || *this == Other) return 1;
	return 0;
}


void Fraction::Reduce() {
	int Re = GCD(this->Num, this->Denom);
	this->Num = this->Num / Re;
	this->Denom = this->Denom / Re;
}

int Fraction::GCD(int a, int b)
{
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

Fraction::~Fraction()
{
}

std::istream& operator>>(std::istream& in, Fraction& Obj) {
	std::cout << "Enter the Num : ";
	in >> Obj.Num;
	std::cout << "Enter the Denom : ";
	in >> Obj.Denom;
	return in;
}

std::ostream& operator<<(std::ostream& out, Fraction& Obj) {
	Obj.Reduce();
	if (Obj.Denom == 1) {
		out << Obj.Num << std::endl;
		return out;
	}
	out << Obj.Num << '/' << Obj.Denom << std::endl;
	return out;
}
