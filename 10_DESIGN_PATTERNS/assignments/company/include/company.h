#include <string>
#include <iostream>
#include <time.h>
#include <vector>
#include "employee.h"
#ifndef COMPANY_H
#define COMPANY_H
using namespace std;
const int YEAR = 2019;

class Company
{
private:
    vector<Employee *> Employee_list;

public:
    void readData();
    void printData();
    double calcSalary();
    Company();
    ~Company();
};
#endif