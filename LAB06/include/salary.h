#ifndef SALARY_H
#define SALARY_H

#include <iostream>
#include <string>
#include "logger.h"

using namespace std;
class Salary
{
public:
    int value;

public:
    // default constructor
    Salary();
    // big three
    Salary(int value);
    Salary(const Salary &other);
    Salary &operator=(const Salary &other);
    ~Salary();
    // compare operator for sorting
    bool operator<(const Salary &other);
    bool operator>(const Salary &other);

    // other methods
    string toString();

    // friend ostream &operator<<(ostream &out, const Salary &salary);
    // friend istream &operator>>(istream &in, Salary &salary);
};

#endif