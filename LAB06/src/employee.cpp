#include "employee.h"

Employee::Employee()
{
    this->ID = 0;
    this->name = "";
    this->workDays = 0;
    this->products = 0;
    this->salary = Salary(0);
}
Employee::Employee(int ID, string name, int workDays, int products)
{
    this->ID = ID;
    this->name = name;
    this->workDays = workDays;
    this->products = products;
    this->salary = Salary(this->workDays * this->products * 1000);
}
Employee::Employee(const Employee &other)
{
    this->ID = other.ID;
    this->name = other.name;
    this->workDays = other.workDays;
    this->products = other.products;
    this->salary = other.salary;
}
Employee &Employee::operator=(const Employee &other)
{
    this->ID = other.ID;
    this->name = other.name;
    this->workDays = other.workDays;
    this->products = other.products;
    this->salary = other.salary;
    return *this;
}
Employee::~Employee()
{
}
string Employee::toString()
{
    Logger *logger = &Logger::getInstance();
    logger->debug("raw salary: " + to_string(this->salary.value));
    return "Employee: ID=" + to_string(ID) + ", Name=" + name + ", WorkDays=" + to_string(workDays) + ", Products=" + to_string(products) + ", Salary=" + salary.toString();
}