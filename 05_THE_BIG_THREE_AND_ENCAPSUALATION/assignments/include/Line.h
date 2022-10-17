#pragma once
#include "Point.h"
#include <iostream>
using namespace std;
class Line
{
	double _a, _b, _c;
public:
	Line();
	Line(double, double, double);
	Point getIntersection(Line l);
	Line getLine(Point A, Point B);
	~Line();
	friend ostream& operator << (ostream & os, const Line l) {
		cout << l._a << "*x + " << l._b << "*y + " << l._c << " = 0";
		return os;
	}
};

