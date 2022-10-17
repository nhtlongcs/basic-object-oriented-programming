#include "Point.h"
#include <math.h>
Point::Point()
{
	this->_x = 0;
	this->_y = 0;
}

Point::Point(double a,double b)
{
	this->_x = a;
	this->_y = b;
}

Point::~Point()
{
}

double Point::getDistTo(Point A)
{
	return sqrt(pow((this->_x - A._x), 2) + pow((this->_y - A._y), 2));
}
Point Point::getCentroid(Point A, Point B) {
	return Point((this->_x + A._x + B._x) / 3.0, (this->_y + A._y + B._y) / 3.0);
}

double Point::getX(Point A) 
{
	return A._x - _x;
}
double Point::getY(Point A)
{
	return A._y -  _y;
}
Point Point::getMidPoint(Point A)
{
	return Point((_x + A._x)/2.0, (_y + A._y)/2.0);
}

double Point::getCoeff(Point A) {
	Point n(A._x - _x,A._y - _y);
	Point M = this->getMidPoint(A);
	return -n._x*M._x - M._y * n._y;
}