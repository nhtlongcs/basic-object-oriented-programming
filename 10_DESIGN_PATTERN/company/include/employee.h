#include <iostream>
#include <string>
#include <cmath>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
const int CURRENT_YEAR = 2022;
using namespace std;

class Employee
{
protected:
    string name;
    int startYear;

public:
    virtual double calcSalary() = 0;
    virtual void readData();
    double experienceBonus();
    Employee();
    Employee(const string &name, const int &startYear);
    Employee(const Employee &);
    ~Employee();
};

class ProductionStaff : public Employee
{
private:
    int numberOfProducts;

public:
    void readData();
    double calcSalary();
    ProductionStaff();
    ProductionStaff(const string &name, const int &startYear, const int &numberOfProducts);
    ProductionStaff(const ProductionStaff &);
    ~ProductionStaff();
};

class Officer : public Employee
{
private:
    int daysOff;
    double baseSalary;

public:
    void readData();
    double calcSalary();
    Officer();
    Officer(const string &name, const int &startYear, const double &baseSalary, const int &daysOff);
    Officer(const Officer &);
    ~Officer();
};

#endif