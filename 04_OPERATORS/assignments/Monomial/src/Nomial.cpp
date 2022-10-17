#include "Nomial.h"

double Nomial::coefficient()
{
	return this->_coefficient;
}
void Nomial::setCoefficient(double coefficient)
{
	this->_coefficient = coefficient;
}
int Nomial::degree()
{
	return this->_degree;
}
void Nomial::setDegree(int degree)
{
	this->_degree = degree;
}
Nomial::Nomial()
{
	this->_degree = 0;
	this->_coefficient = 0;
}
Nomial::Nomial(double coefficient, int degree)
{
	this->_coefficient = coefficient;
	this->_degree = degree;
}
Nomial::~Nomial()
{
	// Code your destructor here!
}

Nomial Nomial::operator+(const Nomial &f)
{
	return Nomial(this->_coefficient + f._coefficient, f._degree);
}
Nomial Nomial::operator*(const Nomial &f)
{
	return Nomial(this->_coefficient * f._coefficient, this->_degree + f._degree);
}
bool Nomial::operator>(const Nomial &f)
{
	return (this->_degree > f._degree || (this->_degree == f._degree && this->_coefficient > f._coefficient));
}
bool Nomial::operator<(const Nomial &f)
{
	return (this->_degree < f._degree || (this->_degree == f._degree && this->_coefficient < f._coefficient));
}
bool Nomial::operator==(const Nomial &f)
{
	return (this->_degree == f._degree && this->_coefficient < f._coefficient);
}

bool Nomial::operator>=(const Nomial &f)
{
	return (*this > f || *this == f);
}
bool Nomial::operator<=(const Nomial &f)
{
	return (*this < f || *this == f);
}
bool Nomial::operator!=(const Nomial &f)
{
	return (!(*this == f));
}

Nomial &Nomial::operator=(const Nomial &f)
{
	this->_degree = f._degree;
	this->_coefficient = f._coefficient;
	return (*this);
}
Nomial &Nomial::operator+=(const Nomial &f)
{
	return (*this = (*this) + f);
}
Nomial &Nomial::operator*=(const Nomial &f)
{
	return (*this = (*this) * f);
}

Nomial &Nomial::operator++()
{
	this->_degree++;
	return (*this);
}
Nomial &Nomial::operator--()
{
	this->_degree--;
	return (*this);
}
Nomial Nomial::operator++(int x)
{
	Nomial temp(*this);
	this->_degree++;
	return (temp);
}
Nomial Nomial::operator--(int x)
{
	Nomial temp(*this);
	this->_degree--;
	return (temp);
}

Nomial &Nomial::operator!()
{
	this->_coefficient *= this->_degree;
	this->_degree--;
	return (*this);
}

ostream &operator<<(ostream &os, const Nomial &f)
{
	os << f._coefficient << "* x^(" << f._degree << ")\n";
	return os;
}

istream &operator>>(istream &is, Nomial &f)
{
	is >> f._degree >> f._coefficient;
	return is;
	// doc thi bo const di
}
