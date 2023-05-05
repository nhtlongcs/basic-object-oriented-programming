#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include "salary.h"
#include "logger.h"

using namespace std;

class Employee
{
private:
    string name;
    int ID;
    int products, workDays;

public:
    Salary salary;

public:
    Employee();
    Employee(int ID, string name, int workDays, int products);

    // big three
    Employee(const Employee &other);
    Employee &operator=(const Employee &other);
    ~Employee();
    // other methods
    string toString();
};
#endif