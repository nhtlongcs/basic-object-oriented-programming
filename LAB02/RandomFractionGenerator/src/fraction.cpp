#include "fraction.h"

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

Fraction::Fraction(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}
Fraction Fraction::rand()
{
    RandomIntegerGenerator *generator = RandomIntegerGenerator::getInstance();
    int numerator = generator->next();
    int denominator = generator->next();
    return Fraction(numerator, denominator);
}
Fraction Fraction::rand(int n_range, int d_range)
{
    RandomIntegerGenerator *generator = RandomIntegerGenerator::getInstance();
    int numerator = generator->next(n_range);
    int denominator = generator->next(d_range);
    return Fraction(numerator, denominator);
}

Fraction Fraction::rand(int range)
{
    Fraction init = Fraction::rand(range, range);
    int numerator = init.numerator + 1;
    int denominator = init.denominator;
    numerator = numerator % denominator;
    numerator += denominator * (range - 1);
    return Fraction(numerator, denominator);
}
std::string Fraction::toString()
{
    return std::to_string(this->numerator) + "/" + std::to_string(this->denominator);
}
std::string Fraction::percentage()
{
    return std::to_string(this->toDouble() * 100) + "%";
}
Fraction Fraction::lowest_terms()
{
    int numerator = this->numerator;
    int denominator = this->denominator;
    int d = gcd(numerator, denominator);
    return Fraction(numerator / d, denominator / d);
}
double Fraction::toDouble()
{
    return (double)this->numerator / (double)this->denominator;
}
Fraction::~Fraction()
{
    // logging purpose only
    // std::cout << "Destructor Fraction called" << std::endl;
}