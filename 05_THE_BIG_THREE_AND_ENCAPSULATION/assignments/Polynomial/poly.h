#ifndef POLY_H
#define POLY_H
#include <iostream>
#include <vector>

class Polynomial
{
private:
    int degree;
    std::vector<double> coeffs;

public:
    Polynomial()
    {
        degree = 0;
        coeffs.push_back(0);
    };
    Polynomial(std::vector<double>, int);
    Polynomial(const Polynomial &other)
    {
        degree = other.degree;
        coeffs = other.coeffs;
    };
    ~Polynomial(){};
    void read();
    int getDegree() const;
    const std::vector<double> getCoeffs() const;

    void print();
};
void Polynomial::read()
{
    std::cout << "Enter the degree of the polynomial: ";
    std::cin >> degree;
    std::cout << "Enter the coefficients of the polynomial: \n";
    for (int i = 0; i < degree + 1; i++)
    {
        double tmp;
        std::cout << "Enter the coefficient of x^" << degree - i << ": ";
        std::cin >> tmp;
        coeffs.push_back(tmp);
    }
}
Polynomial::Polynomial(std::vector<double> c, int d)
{
    coeffs = c;
    degree = d;
}
int Polynomial::getDegree() const
{
    return degree;
}
const std::vector<double> Polynomial::getCoeffs() const
{
    return coeffs;
}
void Polynomial::print()
{
    for (int i = 0; i < degree + 1; i++)
    {
        std::cout << coeffs[i] << "^" << degree - i << " ";
    }
    std::cout << std::endl;
}
#endif