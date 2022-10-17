#ifndef MONOMIAL_H
#define MONOMIAL_H

#include <iostream>
using namespace std;
class Monomial
{
private:
	double m_coefficent;
	int m_exponent;

public:
	void readData();
	void writeData();
	double getCoefficent();
	int getExponent();
	void assignCoefficent(double x);
	void assignExponent(int x);
	double calValue(double x);
	Monomial getDerivatie();
	Monomial add(Monomial f);
	Monomial multifly(Monomial f);
	int compareTo(Monomial f);
};

#endif