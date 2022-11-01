// a parser to serialize and deserialize fraction from text
#ifndef FRAC_H
#define FRAC_H
#include <iostream>
#include <string>
#include <regex>
#include "error.h"
using namespace std;
class Fraction
{
public:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator);
    Fraction() : Fraction(0, 1){};
    ~Fraction();

public:
    static Fraction parse_safe(string input);
    // operator +
    Fraction operator+(const Fraction &f);

public:
    std::string toString();
    std::string percentage();
    Fraction lowest_terms();
    double toDouble();
};
#endif