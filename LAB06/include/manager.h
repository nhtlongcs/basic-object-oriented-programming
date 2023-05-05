#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include "logger.h"
#include "employee.h"

using namespace std;

class EmployeeManager
{
private:
    vector<Employee> employees;

public:
    EmployeeManager();
    EmployeeManager(std::string filepath);
    void sortBySalary();
    void print();

    // big three
    EmployeeManager(const EmployeeManager &other);
    EmployeeManager &operator=(const EmployeeManager &other);
    ~EmployeeManager();
};

#endif