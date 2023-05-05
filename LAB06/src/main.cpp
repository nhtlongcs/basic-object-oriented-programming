#include <iostream>
#include <string>
#include "manager.h"
#include "logger.h"
using namespace std;

int main()
{
    Logger *logger = &Logger::getInstance();
    logger->debug(); // enable debug logs
    string filepath = "data/salary112022.txt";
    EmployeeManager Emanager(filepath);
    Emanager.sortBySalary();
    Emanager.print();
    return 0;
}