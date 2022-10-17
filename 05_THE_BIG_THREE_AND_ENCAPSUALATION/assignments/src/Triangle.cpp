#include "Triangle.h"
#include <math.h>

Triangle::Triangle(Point A, Point B, Point C) {
	this->_A = A;
	this->_B = B;
	this->_C = C;
}
double Triangle::getPerimeter()
{
	return _A.getDistTo(_B) + _A.getDistTo(_C) + _B.getDistTo(_C);
}
double Triangle::getArea()
{
	double p = this->getPerimeter()/2.0;
	return sqrt(p*(p-_A.getDistTo(_B)) *(p- _A.getDistTo(_C)) *(p- _B.getDistTo(_C)));
}

Point Triangle::getCentroid()
{
	return _A.getCentroid(_B, _C);
}
Line Triangle::getMidPer()
{
	Line l;
	l = l.getLine(_A, _B);
	return l;
}
Point Triangle::getCenter()
{
	Line l1,l2;
	l1 = l1.getLine(_A, _B);
	l2 = l2.getLine(_A, _C);
	return l1.getIntersection(l2);
}

Triangle::Triangle()
{
}

Triangle::~Triangle()
{
}
