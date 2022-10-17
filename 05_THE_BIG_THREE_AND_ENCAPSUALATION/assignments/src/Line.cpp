#include "Line.h"



Line::Line()
{
	_a = 0;
	_b = 0;
	_c = 0;
}
Line::Line(double a, double b, double c)
{
	_a = a;
	_b = b;
	_c = c;
}
Line Line::getLine(Point A, Point B)
{
	return Line(A.getX(B),A.getY(B),A.getCoeff(B));
}
Point Line::getIntersection(Line l)
{
	double D = _a * l._b - l._a*_b;
	double Dx = -(_c*l._b - l._c*_b);
	double Dy = -(_a*l._c - l._a*_c);
	if (D != 0) return Point(Dx / D, Dy / D);
	else
		return Point(-100000, -100000);
}

Line::~Line()
{
}
