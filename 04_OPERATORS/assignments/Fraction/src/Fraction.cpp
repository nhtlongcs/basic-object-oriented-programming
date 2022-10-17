#include "Fraction.h" 

int Fraction::numerator()
{
	return this->_numerator;
}
void Fraction::setNumerator(int numerator)
{
	this->_numerator = numerator;
}
int Fraction::denominator()
{
	return this->_denominator;
}
void Fraction::setDenominator(int denominator)
{
	this->_denominator = denominator;
}

bool Fraction::operator > (const Fraction &p) 
{
	return ((double)this->_numerator / (double)this->_denominator > (double)p._numerator / (double)p._denominator);
};
bool Fraction::operator < (const Fraction &p) {
	return ((double)this->_numerator / (double)this->_denominator < (double)p._numerator / (double)p._denominator);

};
bool Fraction::operator == (const Fraction &p) {
	return ((double)this->_numerator / (double)this->_denominator == (double)p._numerator / (double)p._denominator);

};
bool Fraction::operator >= (const Fraction &p) {
	return ((double)this->_numerator / (double)this->_denominator >= (double)p._numerator / (double)p._denominator);

};
bool Fraction::operator <= (const Fraction &p) {
	return ((double)this->_numerator / (double)this->_denominator <= (double)p._numerator / (double)p._denominator);

};
bool Fraction::operator != (const Fraction &p) {
	return ((double)this->_numerator / (double)this->_denominator != (double)p._numerator / (double)p._denominator);

};

Fraction Fraction::operator + (const Fraction& p) 
{
	Fraction Temp;
	Temp._numerator = this->_numerator*p._denominator + this->_denominator*p._numerator;
	Temp._denominator = this->_denominator*p._denominator;
	return Temp;
};
Fraction Fraction::operator * (const Fraction& p) {
	Fraction Temp;
	Temp._numerator = this->_numerator*p._numerator;
	Temp._denominator = this->_denominator*p._denominator;
	return Temp;
};

Fraction& Fraction::operator = (const Fraction&p) {
	this->_numerator = p._numerator;
	this->_denominator = p._denominator;
	return (*this);
};
Fraction& Fraction::operator += (const Fraction&p) {

	return ((*this)=(*this)+p);
};
Fraction& Fraction::operator *= (const Fraction&p) {

	return ((*this) = (*this) * p);
};


Fraction& Fraction::operator++ () {
	return((*this) = (*this) + Fraction(1, 1));
}

Fraction& Fraction::operator--() {
	return((*this) = (*this) + Fraction(-1, 1));
}
Fraction Fraction::operator++(int x)
{
	Fraction Temp = *this;
	(*this) = (*this) + Fraction(1, 1);
	return Temp;
}
Fraction Fraction::operator--(int x) 
{
	Fraction Temp = *this;
	(*this) = (*this) + Fraction(-1, 1);
	return Temp;
}

ostream& operator << (ostream& os, Fraction p) 
{
	os << p._numerator << " / " << p._denominator;
	return os;
};

istream& operator >> (istream& is, Fraction &p) 
{
	is >> p._numerator >> p._denominator;
	return is;
};

Fraction::operator int() {
	return this->_numerator / this->_denominator;
}

Fraction::operator double() {
	return (double)this->_numerator / this->_denominator;
}


Fraction::Fraction()
{
	//Code your constructor here! 
	this->_denominator = 0;
	this->_numerator = 0;

}
Fraction::Fraction(int numerator, int denominator)
{
	this->_numerator = numerator;
	this->_denominator = denominator;
}
Fraction::~Fraction()
{
	//Code your destructor here! 

}
