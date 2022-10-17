#ifndef NOMIAL_H
#define NOMIAL_H
#include <iostream>
using namespace std;

class Nomial
{
private:
	double _coefficient;
	int _degree;

public:
	double coefficient();
	void setCoefficient(double coefficient);
	int degree();
	void setDegree(int degree);

public:
	Nomial();
	Nomial(double coefficient, int degree);
	~Nomial();
	Nomial operator+(const Nomial &f);
	Nomial operator*(const Nomial &f);
	bool operator>(const Nomial &f);
	bool operator<(const Nomial &f);
	bool operator==(const Nomial &f);
	bool operator>=(const Nomial &f);
	bool operator<=(const Nomial &f);
	bool operator!=(const Nomial &f);

	Nomial &operator=(const Nomial &f);
	Nomial &operator+=(const Nomial &f);
	Nomial &operator*=(const Nomial &f);

	Nomial &operator++();
	Nomial &operator--();
	Nomial operator++(int x);
	Nomial operator--(int x);
	Nomial &operator!();

	friend ostream &operator<<(ostream &os, const Nomial &f);
	friend istream &operator>>(istream &is, Nomial &f);
};

#endif