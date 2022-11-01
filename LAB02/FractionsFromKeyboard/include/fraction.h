// a parser to serialize and deserialize fraction from text
#ifndef FRAC_H
#define FRAC_H
#include <iostream>
#include <string>
#include <regex>
#include "error.h"
#include "igenerators.h"
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
    static Fraction read_safe(int min, int max);
    // operator +
    Fraction operator+(const Fraction &f);

public:
    static Fraction rand();
    static Fraction rand(int n_range, int d_range);
    static Fraction rand(int range);

public:
    std::string toString();
    std::string percentage();
    Fraction lowest_terms();
    double toDouble();
};
#endif