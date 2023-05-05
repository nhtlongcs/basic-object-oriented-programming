#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <regex>
using namespace std;

class Employee
{
public:
    virtual int salary() = 0;
    virtual string toString() = 0;
    virtual ~Employee() = default;

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
class ProductEmployee : public Employee
{
public:
    int productCount;
    int paymentPerProduct;
    ProductEmployee(int productCount, int paymentPerProduct)
    {
        this->productCount = productCount;
        this->paymentPerProduct = paymentPerProduct;
    }
    int salary()
    {
        return productCount * paymentPerProduct;
    }
    string toString()
    {
        return "Product employee";
    }
    ~ProductEmployee() = default;
};

class DailyEmployee : public Employee
{
public:
    int dayCount;
    int paymentPerPay;
    DailyEmployee(int dayCount, int paymentPerPay)
    {
        this->dayCount = dayCount;
        this->paymentPerPay = paymentPerPay;
    }
    int salary()
    {
        return dayCount * paymentPerPay;
    }
    string toString()
    {
        return "Daily employee";
    }
    ~DailyEmployee() = default;
};
class Manager : public Employee
{
public:
    int employeeCount;
    int paymentPerEmployee;
    int baseSalary;
    Manager(int employeeCount, int paymentPerEmployee, int baseSalary)
    {
        this->employeeCount = employeeCount;
        this->paymentPerEmployee = paymentPerEmployee;
        this->baseSalary = baseSalary;
    }
    int salary()
    {
        return employeeCount * paymentPerEmployee + baseSalary;
    }
    string toString()
    {
        return "Manager";
    }
    ~Manager() = default;
};
class IParsable
{
public:
    IParsable()
    {
        // logger->debug("IParsable::IParsable() is called");
    }
    virtual string parsedObjectName() = 0;
    virtual Employee *parse(string line) = 0;
    ~IParsable() = default;
};
class DailyEmployeeParser : public IParsable
{
public:
    string parsedObjectName()
    {
        return "DailyEmployee";
    }
    Employee *parse(string line)
    {
        int dayCount = 0;
        int paymentPerPay = 0;
        regex pattern("dayCount=(\\d+), paymentPerPay=(\\d+)");
        smatch match;
        if (regex_search(line, match, pattern))
        {
            dayCount = stoi(match[1]);
            paymentPerPay = stoi(match[2]);
        }
        return new DailyEmployee(dayCount, paymentPerPay);
    }
    ~DailyEmployeeParser() = default;
};
class ProductEmployeeParser : public IParsable
{
public:
    string parsedObjectName()
    {
        return "ProductEmployee";
    }
    Employee *parse(string line)
    {
        int productCount = 0;
        int paymentPerProduct = 0;
        regex pattern("productCount=(\\d+), paymentPerProduct=(\\d+)");
        smatch match;
        if (regex_search(line, match, pattern))
        {
            productCount = stoi(match[1]);
            paymentPerProduct = stoi(match[2]);
        }
        return new ProductEmployee(productCount, paymentPerProduct);
    }
    ~ProductEmployeeParser() = default;
};

class ManagerParser : public IParsable
{
public:
    string parsedObjectName()
    {
        return "Manager";
    }
    Employee *parse(string line)
    {
        int employeeCount = 0;
        int salaryPerMonth = 0;
        int baseSalary = 0;
        regex pattern("employeeCount=(\\d+), paymentPerEmployee=(\\d+), baseSalary=(\\d+)");
        smatch match;
        if (regex_search(line, match, pattern))
        {
            employeeCount = stoi(match[1]);
            salaryPerMonth = stoi(match[2]);
            baseSalary = stoi(match[3]);
        }
        return new Manager(employeeCount, salaryPerMonth, baseSalary);
    }
    ~ManagerParser() = default;
};

class ParserFactory
{
public:
    map<string, IParsable *> _container; // A container for all the dependencies injection
public:
    void registerWith(IParsable *parser)
    { // Do the injection here
        _container.insert(
            {parser->parsedObjectName(), parser});
    }

    IParsable *create(string type)
    {
        // logger->debug("ParserFactory::create() is called");
        // logger->debug("type = " + type);
        return _container[type]; // Ask container to resolve the needed type
    }
    ~ParserFactory()
    {
        for (auto it = _container.begin(); it != _container.end(); it++)
        {
            delete it->second;
        }
    }
};

int main()
{
    // Product employee, salary:15.800.000 d
    // Daily employee, salary:20.000.000 d
    // Product employee, salary:15.390.000 d
    // Product employee, salary:16.200.000 d
    // Manager, salary:25.000.000 d
    // Daily employee, salary:24.200.000 d
    // Manager, salary:19.000.000 d
    // Daily employee, salary:27.000.000 d
    // Manager, salary:15.500.000 d
    ParserFactory factory;
    factory.registerWith(new ProductEmployeeParser());
    factory.registerWith(new DailyEmployeeParser());
    factory.registerWith(new ManagerParser());

    vector<string> lines = {
        "ProductEmployee productCount=790, paymentPerProduct=20000",
        "DailyEmployee dayCount=20, paymentPerPay=1000000",
        "ProductEmployee productCount=810, paymentPerProduct=19000",
        "ProductEmployee productCount=900, paymentPerProduct=18000",
        "Manager employeeCount=49, paymentPerEmployee=500000, baseSalary=6000000",
        "DailyEmployee dayCount=22, paymentPerPay=1100000",
        "Manager employeeCount=37, paymentPerEmployee=500000, baseSalary=7000000",
        "DailyEmployee dayCount=18, paymentPerPay=1500000",
        "Manager employeeCount=30, paymentPerEmployee=500000, baseSalary=5000000"};

    vector<Employee *> employees;

    for (string line : lines)
    { // "ProductEmployee productCount=790, paymentPerProduct=20000"
        int splitPosition = line.find_first_of(" ");
        string type = line.substr(0, splitPosition); // type = "ProductEmployee"
        IParsable *parser = factory.create(type);

        // data = "productCount=790, paymentPerProduct=20000",
        string data = line.substr(splitPosition + 1, line.length() - splitPosition - 1);
        Employee *employee = dynamic_cast<Employee *>(parser->parse(data));
        employees.push_back(employee);
    }

    for (auto employee : employees)
    {
        cout << employee->toString() << ", salary: " << Employee::toCurrencyString(employee->salary()) << endl;
    }
}