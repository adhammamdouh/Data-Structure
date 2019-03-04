#pragma once
class Fraction
{
private:
	int Num;
	int Denom;
	void Reduce();
public:
	Fraction();
	Fraction(int Num, int Denom);

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
	std::istream& operator>>(std::istream& in);
	std::ostream& operator<<(std::ostream& out);
	virtual ~Fraction();
};

