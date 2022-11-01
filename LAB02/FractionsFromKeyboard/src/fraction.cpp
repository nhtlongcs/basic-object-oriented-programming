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
Fraction Fraction::operator+(const Fraction &f)
{
    int numerator = this->numerator * f.denominator + this->denominator * f.numerator;
    int denominator = this->denominator * f.denominator;
    return Fraction(numerator, denominator).lowest_terms();
}
bool inRange(int min, int max, int value)
{
    return value >= min && value <= max;
}
Fraction Fraction::read_safe(int min, int max)
{
    auto e = &Error::getInstance();
    string buffer;
    Fraction result = Fraction(0, 1);
    e->setErrorCode(ErrorCode::OK);
    getline(cin, buffer);
    if (buffer == "")
    {
        e->setErrorCode(ErrorCode::EmptyInput);
        return result;
    }

    string pattern = "\\d+\\/\\d+"; // \d: digits only 0-9, +: one or more
    bool matched = regex_match(buffer, regex(pattern));
    if (!matched)
    {
        e->setErrorCode(ErrorCode::InvalidFormat);
        return result;
    }
    else
    {
        int pos = buffer.find("/");
        int numerator = std::stoi(buffer.substr(0, pos));
        int denominator = std::stoi(buffer.substr(pos + 1));
        if (denominator == 0)
        {
            e->setErrorCode(ErrorCode::DivideByZero);
            return result;
        }
        result = Fraction(numerator, denominator);
    }
    if (!(inRange(min, max, result.numerator) && inRange(min, max, result.denominator)))
    {
        e->setErrorCode(ErrorCode::OutOfRange);
        return result;
    }
    return result;
}
