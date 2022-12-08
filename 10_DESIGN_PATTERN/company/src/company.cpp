#include "company.h"

void Company::readData()
{
    int n = 0;
    cout << "Enter number of employees: ";
    cin >> n;
    Employee_list.resize(n);
    for (int i = 0; i < Employee_list.size(); ++i)
    {
        cout << "Enter information for employee [" << i << "]: \n";
        int t;
        cout << "Enter type of employee (1: Production staff, 2: Officer): ";
        cin >> t;
        if (t == 1)
            Employee_list[i] = new ProductionStaff();
        else
            Employee_list[i] = new Officer();
        Employee_list[i]->readData();
        cout << "------------------- \n";
    }
}

double Company::calcSalary()
{
    double Sum = 0;
    for (int i = 0; i < Employee_list.size(); ++i)
    {
        Sum += Employee_list[i]->calcSalary();
    }
    return Sum;
}

void Company::printData()
{
    cout << "Number of employees: " << Employee_list.size() << endl;
    for (int i = 0; i < Employee_list.size(); ++i)
    {
        cout << "Employee [" << i << "]: ";
        cout << (int)Employee_list[i]->calcSalary() << endl;
        cout << "------------------- \n";
    }
    cout << "Total salary: " << (int)calcSalary() << endl;
}
Company::Company()
{
    Employee_list.resize(0);
}
Company::~Company()
{
    for (int i = 0; i < Employee_list.size(); ++i)
    {
        delete Employee_list[i];
    }
}