#include "Fraction.h"
#include <cmath>
#include <iostream>


Fraction::Fraction()
{
	this->Num = 0;
	this->Denom = 1;
}

Fraction::Fraction(int Num, int Denom) {
	this->Num = Num;
	this->Denom = (Denom == 0) ? 1 : 0;
	Reduce();
}

Fraction Fraction::operator-(Fraction& Other) {
	Fraction tmp;
	tmp.Num = ((this->Num*Other.Denom) - (Other.Num * this->Denom));
	tmp.Denom = (this->Denom * Other.Denom);
	tmp.Reduce();
	return tmp;
}

Fraction Fraction::operator+ (Fraction& Other) {
	Fraction tmp;
	tmp.Num = ((this->Num*Other.Denom) - (Other.Num * this->Denom));
	tmp.Denom = (this->Denom * Other.Denom);
	tmp.Reduce();
	return tmp;
}

Fraction Fraction::operator*(Fraction& Other) {
	Fraction tmp;
	tmp.Num = (this->Num * Other.Num);
	tmp.Denom = (this->Denom * Other.Denom);
	tmp.Reduce();
	return tmp;
}

Fraction Fraction::operator/(Fraction& Other) {
	Fraction tmp;
	tmp.Num = (this->Num * Other.Denom);
	tmp.Denom = (this->Denom * Other.Num);
	tmp.Reduce();
	return tmp;
}

Fraction& Fraction::operator+=(Fraction& Other) {
	this->Num = ((this->Num*Other.Denom) + (Other.Num * this->Denom));
	this->Denom = (this->Denom * Other.Denom);
	this->Reduce();
	return *this;
}

Fraction& Fraction::operator-=(Fraction& Other) {
	this->Num = ((this->Num*Other.Denom) - (Other.Num * this->Denom));
	this->Denom = (this->Denom * Other.Denom);
	this->Reduce();
	return *this;
}

Fraction& Fraction::operator*=(Fraction& Other) {
	this->Num = (this->Num * Other.Num);
	this->Denom = (this->Denom * Other.Denom);
	this->Reduce();
	return *this;
}

Fraction& Fraction::operator/=(Fraction& Other) {
	this->Num = (this->Num * Other.Denom);
	this->Denom = (this->Denom * Other.Num);
	this->Reduce();
	return *this;
}

Fraction& Fraction::operator=(Fraction& Other) {
	this->Num = Other.Num;
	this->Denom = Other.Denom;
	this->Reduce();
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

std::istream& Fraction::operator>>(std::istream& in){
	std::cout << "Enter the Num : ";
	in >> this->Num;
	std::cout << "Enter the Denom : ";
	in >> this->Denom;
	return in;
}

std::ostream& Fraction::operator<<(std::ostream& out) {
	if (this->Num == 0) {
		out << 0 << std::endl;
		return out;
	}
	out << this->Num << '/' << this->Denom << std::endl;
	return out;
}


void Fraction::Reduce() {
	if (this->Num / this->Denom == ceill(this->Num / this->Denom)) {
		this->Num /= this->Denom;
		this->Denom /= this->Denom;
	}
	else if(this->Denom / this->Num == ceill(this->Denom / this->Num))
	{
		this->Num /= this->Num;
		this->Denom /= this->Num;
	}
}

Fraction::~Fraction()
{
}
