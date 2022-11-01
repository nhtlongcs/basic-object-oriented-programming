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
    int denominator = generator->next() + 1;
    return Fraction(numerator, denominator);
}
Fraction Fraction::rand(int n_range, int d_range)
{
    RandomIntegerGenerator *generator = RandomIntegerGenerator::getInstance();
    int numerator = generator->next(n_range) + 1;
    int denominator = generator->next(d_range) + 1;
    return Fraction(numerator, denominator);
}

Fraction Fraction::rand(int range)
{
    Fraction init = Fraction::rand(range, range);
    int numerator = init.numerator;
    int denominator = init.denominator;
    numerator = numerator % denominator;
    numerator += denominator * (range - 1);
    return Fraction(numerator, denominator);
}

std::string Fraction::toString()
{
    std::string result = "";
    int coeff = numerator / denominator;
    if (coeff != 0)
    {
        result += std::to_string(coeff);
        result += " ";
    }
    int remainder = numerator % denominator;
    if (remainder != 0)
    {
        result += std::to_string(remainder);
        result += "/";
        result += std::to_string(denominator);
    }
    return result;
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