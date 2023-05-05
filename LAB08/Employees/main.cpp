#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee
{
public:
    virtual int salary() = 0;
    // static to currency string
    static string toCurrencyString(int value)
    {
        string str = to_string(value);
        int len = str.length();
        int i = 0;
        while (i < len - 3)
        {
            str.insert(len - 3 - i, ".");
            i += 3;
        }
        return str + " d";
    }
};

class DailyEmployee : public Employee
{
public:
    int numberOfDays;
    int paymentPerDay;

public:
    DailyEmployee(int numberOfDays, int paymentPerDay)
    {
        this->numberOfDays = numberOfDays;
        this->paymentPerDay = paymentPerDay;
    }
    int salary()
    {
        return numberOfDays * paymentPerDay;
    }
};

class ProductEmployee : public Employee
{
public:
    int numberOfProducts;
    int paymentPerProduct;

public:
    ProductEmployee(int numberOfProducts, int paymentPerProduct)
    {
        this->numberOfProducts = numberOfProducts;
        this->paymentPerProduct = paymentPerProduct;
    }
    int salary()
    {
        return numberOfProducts * paymentPerProduct;
    }
};

class Manager : public Employee
{
public:
    int numberOfManagedEmployees;
    int fixedBasePaymentPerMonth;

public:
    Manager(int numberOfManagedEmployees, int fixedBasePaymentPerMonth)
    {
        this->numberOfManagedEmployees = numberOfManagedEmployees;
        this->fixedBasePaymentPerMonth = fixedBasePaymentPerMonth;
    }
    int salary()
    {
        return fixedBasePaymentPerMonth + numberOfManagedEmployees * 1000000;
    }
};

int main()
{
    // Daily employee, salary: 20.000.000 d
    // Daily employee, salary: 24.200.000 d
    // Daily employee, salary: 27.000.000 d
    // Product employee, salary: 15.800.000 d
    // Product employee, salary: 15.390.000 d
    // Product employee, salary: 16.200.000 d
    // Manager, salary: 20.000.000 d
    // Manager, salary: 30.500.000 d
    // Manager, salary: 25.500.000 d
    vector<DailyEmployee *> dailyEmployees = {
        new DailyEmployee(20, 1000000), // number of days, payment per day
        new DailyEmployee(22, 1100000),
        new DailyEmployee(18, 1500000)};

    // Daily employee's salary = number of days * payment per day
    for (DailyEmployee *employee : dailyEmployees)
    {
        cout << "Daily employee, salary: " << Employee::toCurrencyString(employee->salary()) << endl;
    }

    vector<ProductEmployee *> productEmployees = {
        new ProductEmployee(790, 20000), // number of products, payment per product
        new ProductEmployee(810, 19000),
        new ProductEmployee(900, 18000)};

    // Product employee's salary = number of products * payment per product
    for (ProductEmployee *employee : productEmployees)
    {
        cout << "Product employee, salary: " << Employee::toCurrencyString(employee->salary()) << endl;
    }

    vector<Manager *> managers = {
        new Manager(30, 5000000), // number of managed employees, fixed base payment per month
        new Manager(49, 6000000),
        new Manager(37, 7000000)};

    // Manager's salary = number of managed employees * 500.000 + fixed base payment per month
    for (Manager *employee : managers)
    {
        cout << "Manager, salary: " << Employee::toCurrencyString(employee->salary()) << endl;
    }
}