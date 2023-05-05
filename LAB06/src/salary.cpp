#include "salary.h"
Salary::Salary()
{
    value = 0;
}
Salary::Salary(int value)
{
    this->value = value;
}
Salary::Salary(const Salary &other)
{
    this->value = other.value;
}
Salary &Salary::operator=(const Salary &other)
{
    this->value = other.value;
    return *this;
}
Salary::~Salary()
{
}
string Salary::toString()
{
    // currency format: add dot after every 3 digits
    string str = to_string(value);
    int len = str.length();
    int dotPos = len % 3;
    if (dotPos == 0)
        dotPos = 3;
    for (int i = dotPos; i < len; i += 4)
    {
        str.insert(i, ".");
    }
    return str + " đ";
}

bool Salary::operator<(const Salary &other)
{
    return this->value < other.value;
}
bool Salary::operator>(const Salary &other)
{
    return this->value > other.value;
}