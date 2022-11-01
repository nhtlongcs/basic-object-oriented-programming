#include "point.h"

Point::Point(int x, int y)
{
    this->_x = x;
    this->_y = y;
}
Point Point::rand()
{
    RandomIntegerGenerator *generator = RandomIntegerGenerator::getInstance();
    int x = generator->next();
    int y = generator->next() + 1;
    return Point(x, y);
}
Point Point::rand(int x_range, int y_range)
{
    RandomIntegerGenerator *generator = RandomIntegerGenerator::getInstance();
    int x = generator->next(x_range - 1) + 1;
    int y = generator->next(y_range - 1) + 1;
    return Point(x, y);
}
std::string Point::toString()
{
    return "(" + std::to_string(this->_x) + ", " + std::to_string(this->_y) + ")";
}
Point::~Point()
{
    // logging purpose only
    // std::cout << "Destructor Point called" << std::endl;
}