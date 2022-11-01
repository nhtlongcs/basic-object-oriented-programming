// a parser to serialize and deserialize fraction from text
#ifndef FRAC_H
#define FRAC_H
#include <iostream>
#include "igenerators.h"
class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator);
    ~Fraction();
    static Fraction rand();
    static Fraction rand(int n_range, int d_range);
    std::string toString();
    std::string percentage();
    Fraction lowest_terms();
    double toDouble();
};
#endif