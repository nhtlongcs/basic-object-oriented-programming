#include "employee.h"

void Employee::readData()
{
    cout << "Enter employee name: ";
    cin >> name;
    getline(cin, name);
    cout << "Enter start year: ";
    cin >> startYear;
}
double Employee::experienceBonus()
{
    return 500000 + 50000 * max(CURRENT_YEAR - startYear, 0);
}
Employee::Employee()
{
    name = "";
    startYear = CURRENT_YEAR;
}
Employee::Employee(const string &name, const int &startYear)
{
    this->name = name;
    this->startYear = startYear;
}
Employee::Employee(const Employee &e)
{
    name = e.name;
    startYear = e.startYear;
}

Employee::~Employee() {}

void ProductionStaff::readData()
{
    Employee::readData();
    cout << "Enter number of products: ";
    cin >> numberOfProducts;
}
double ProductionStaff::calcSalary()
{
    return Employee::experienceBonus() + numberOfProducts * 10000;
}

ProductionStaff::ProductionStaff() : Employee()
{
    numberOfProducts = 0;
}
ProductionStaff::ProductionStaff(const string &name, const int &startYear, const int &numberOfProducts) : Employee(name, startYear)
{
    this->numberOfProducts = numberOfProducts;
}
ProductionStaff::ProductionStaff(const ProductionStaff &e) : Employee(e)
{
    numberOfProducts = e.numberOfProducts;
}
ProductionStaff::~ProductionStaff()
{
}

void Officer::readData()
{
    Employee::readData();
    cout << "Enter base salary: ";
    cin >> baseSalary;
    cout << "Enter number of days off: ";
    cin >> daysOff;
}
double Officer::calcSalary()
{
    return Employee::experienceBonus() + baseSalary - daysOff * 10000;
}

Officer::Officer() : Employee()
{
    startYear = CURRENT_YEAR;
    baseSalary = 0;
}
Officer::Officer(const string &name, const int &startYear, const double &baseSalary, const int &daysOff) : Employee(name, startYear)
{
    this->baseSalary = baseSalary;
    this->daysOff = daysOff;
}
Officer::Officer(const Officer &e) : Employee(e)
{
    this->baseSalary = e.baseSalary;
    this->daysOff = e.daysOff;
}
Officer::~Officer() {}
