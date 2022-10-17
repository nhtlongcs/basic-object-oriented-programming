#include "monomial.h"
#include <math.h>
void Monomial::readData()
{
	cin >> this->m_coefficent >> this->m_exponent;
}
void Monomial::writeData()
{
	cout << this->m_coefficent << "*x^" << this->m_exponent << "\n";
}
double Monomial::getCoefficent()
{
	return this->m_coefficent;
}
int Monomial::getExponent()
{
	return this->m_exponent;
}
void Monomial::assignCoefficent(double x)
{
	this->m_coefficent = x;
}
void Monomial::assignExponent(int x)
{
	this->m_exponent = x;
}
double Monomial::calValue(double x)
{
	return this->m_coefficent * pow(x, double(this->m_exponent));
}
Monomial Monomial::getDerivatie()
{
	Monomial g;
	g.m_coefficent = this->m_coefficent * (double)this->m_exponent;
	g.m_exponent = this->m_exponent - 1;
	return g;
}
Monomial Monomial::add(Monomial f)
{
	Monomial g;
	g.m_coefficent = f.m_coefficent + this->m_coefficent;
	g.m_exponent = f.m_exponent;
	return g;
}
Monomial Monomial::multifly(Monomial f)
{
	Monomial g;
	g.m_coefficent = f.m_coefficent * this->m_coefficent;
	g.m_exponent = f.m_exponent + this->m_exponent;
	return g;
}
int Monomial::compareTo(Monomial f)
{
	if (this->m_exponent < f.m_exponent)
		return -1;
	else if (this->m_exponent > f.m_exponent)
		return 1;
	else
		return (this->m_coefficent < f.m_coefficent ? (-1) : (this->m_coefficent > f.m_coefficent));
}