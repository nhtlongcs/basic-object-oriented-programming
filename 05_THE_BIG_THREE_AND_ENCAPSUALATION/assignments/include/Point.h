#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
	double _x, _y;
public:
	Point();
	Point(double, double);
	double getDistTo(Point);
	Point getCentroid(Point, Point);
	Point getMidPoint(Point A);
	double getX(Point A);
	double getY(Point A);
	double getCoeff(Point A);
	~Point();
	friend ostream& operator << (ostream & os, const Point A) {
		cout << "(" << A._x << " , " << A._y<<")";
		return os;
	}
};

