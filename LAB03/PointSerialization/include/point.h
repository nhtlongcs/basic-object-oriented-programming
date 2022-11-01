// a parser to serialize and deserialize Point from text
#ifndef FRAC_H
#define FRAC_H
#include <iostream>
#include "igenerators.h"
class Point
{
private:
    int _x;
    int _y;

public:
    Point(int x, int y);
    Point() : Point(0, 0){};
    ~Point();
    static Point rand();
    static Point rand(int x_min, int y_min, int x_max, int y_max);
    static Point rand(int x_range, int y_range);
    std::string toString();
};
#endif