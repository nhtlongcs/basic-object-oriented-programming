#include <iostream>

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {}
    Fraction(const Fraction &f) : numerator(f.numerator), denominator(f.denominator) {}
    Fraction &operator=(const Fraction &f)
    {
        numerator = f.numerator;
        denominator = f.denominator;
        return *this;
    }
    ~Fraction() {}

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
    void setNumerator(int num) { numerator = num; }
    void setDenominator(int den) { denominator = den; }

    void read()
    {
        std::cin >> numerator >> denominator;
    }
    void write() const
    {
        std::cout << numerator << "/" << denominator << std::endl;
    }
    Fraction inverse() const
    {
        return Fraction(denominator, numerator);
    }
    static int gcd(int a, int b)
    {
        while (b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
    void compress()
    {
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }
    // Operators
    Fraction operator+(const Fraction &f) const
    {
        return Fraction(numerator * f.denominator + denominator * f.numerator, denominator * f.denominator);
    }
    Fraction operator*(const Fraction &f) const
    {
        Fraction x = Fraction(numerator * f.numerator, denominator * f.denominator);
        x.compress();
        return x;
    }
    bool operator>(const Fraction &f) const
    {
        return numerator * f.denominator > denominator * f.numerator;
    }
    bool operator<(const Fraction &f) const
    {
        return numerator * f.denominator < denominator * f.numerator;
    }
    bool operator==(const Fraction &f) const
    {
        return numerator * f.denominator == denominator * f.numerator;
    }
};