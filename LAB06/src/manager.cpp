#include "manager.h"

EmployeeManager::EmployeeManager()
{
    // Default constructor
}

EmployeeManager::EmployeeManager(std::string filepath)
{
    // Employee ID=21, Name=Nguyen Minh Hanh, WorkDay=12, Products=770
    string employee_pattern = "Employee ID=(\\d+), Name=([^,]*), WorkDay=(\\d+), Products=(\\d+)";
    string int_pattern = "\\d+";

    std::ifstream file(filepath);
    std::string line;
    std::getline(file, line);
    std::smatch match;
    int number_of_employees = 0;
    Logger *logger = &Logger::getInstance();

    if (std::regex_search(line, match, std::regex(int_pattern)))
    {
        number_of_employees = stoi(match[0]);
    }
    logger->debug("Number of employees: " + to_string(number_of_employees));

    for (int i = 0; i < number_of_employees; i++)
    {
        std::getline(file, line);
        logger->debug("Line: " + line);
        if (std::regex_search(line, match, std::regex(employee_pattern)))
        {
            int ID = stoi(match[1]);
            string name = match[2];
            int workDays = stoi(match[3]);
            int products = stoi(match[4]);
            double salary = 0;

            Employee employee(ID, name, workDays, products);
            employees.push_back(employee);
        }
        else
        {
            logger->debug("Error: Employee pattern not found");
        }
    }
}
void EmployeeManager::sortBySalary()
{
    Logger *logger = &Logger::getInstance();
    logger->debug("Printing raw employees");
    for (int i = 0; i < employees.size(); i++)
    {
        logger->debug(employees[i].toString());
    }

    for (int i = 0; i < employees.size(); i++)
    {
        for (int j = i + 1; j < employees.size(); j++)
        {
            if (employees[i].salary < employees[j].salary)
            {
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}
void EmployeeManager::print()
{
    Logger *logger = &Logger::getInstance();

    logger->debug("Printing employees");
    for (int i = 0; i < employees.size(); i++)
    {

        logger->info(employees[i].toString());
    }
}
EmployeeManager::EmployeeManager(const EmployeeManager &other)
{
    // Copy constructor
    this->employees = other.employees;
}
EmployeeManager &EmployeeManager::operator=(const EmployeeManager &other)
{
    // Assignment operator
    if (this != &other)
    {
        this->employees = other.employees;
    }
    return *this;
}
EmployeeManager::~EmployeeManager()
{
    // Destructor
}