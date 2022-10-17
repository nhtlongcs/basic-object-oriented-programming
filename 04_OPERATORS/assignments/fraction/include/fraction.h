#ifndef FRAC_H
#define FRAC_H

#include <iostream>
#include <cmath>
using namespace std;
class Fraction
{
private:
	int _numerator, _denominator;

public:
	int numerator();
	void setNumerator(int numerator);
	int denominator();
	void setDenominator(int denominator);

	Fraction compress();
	Fraction operator+(const Fraction &);
	Fraction operator*(const Fraction &);

	bool operator>(const Fraction &);
	bool operator<(const Fraction &);
	bool operator==(const Fraction &);
	bool operator>=(const Fraction &);
	bool operator<=(const Fraction &);
	bool operator!=(const Fraction &);

	Fraction &operator=(const Fraction &);
	Fraction &operator+=(const Fraction &);
	Fraction &operator*=(const Fraction &);

	Fraction &operator++();
	Fraction &operator--();
	Fraction operator++(int);
	Fraction operator--(int);
	operator int();
	operator double();
	friend ostream &operator<<(ostream &, Fraction);
	friend istream &operator>>(istream &, Fraction &);

public:
	Fraction();
	Fraction(int numerator, int denominator);
	~Fraction();
};

#endif