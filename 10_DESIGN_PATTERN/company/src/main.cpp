#include <iostream>
#include <company.h>

using namespace std;

int main()
{
    Company c = Company();
    c.readData();
    c.printData();
    return 0;
}