// class Fraction
// Implement read, write methods
// Implement get and set methods
// Implement inverse, compress methods
// Implement operators +, -, *, /, +=, -=, *=, /=, ==, !=, <, >, <=, >=

#include <iostream>
#include "fraction.h"
int main()
{
    Fraction x, y;
    std::cout << "Enter x: ";
    x.read();
    std::cout << "X is: ";
    x.write();
    std::cout << "X after inverse is: ";
    x.inverse().write();
    std::cout << "X after compress is: ";
    x.compress();
    x.write();
    std::cout << "Enter y: ";
    y.read();
    std::cout << "Y is: ";
    y.write();
    Fraction sum = x + y;
    std::cout << "X + Y is: ";
    sum.write();
    Fraction mul = x * y;
    std::cout << "X * Y is: ";
    mul.write();
    std::cout << "X > Y is: " << ((x > y) ? "true" : "false") << std::endl;
    std::cout << "X < Y is: " << ((x < y) ? "true" : "false") << std::endl;
    std::cout << "X == Y is: " << ((x == y) ? "true" : "false") << std::endl;
    return 0;
}