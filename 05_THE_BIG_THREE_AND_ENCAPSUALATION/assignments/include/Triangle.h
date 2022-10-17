#pragma once
#include "Point.h"
#include "Line.h"
#include <iostream>
using namespace std;
class Triangle
{
	Point _A, _B, _C;
public:
	Triangle();
	Triangle(Point, Point, Point);
	~Triangle();
	double getPerimeter();
	double getArea();
	Line getMidPer();
	Point getCenter();
	Point getCentroid();
	friend ostream& operator << (ostream & os, const Triangle T) {
		cout << "( " << T._A <<  " , " << T._B << " , " << T._C << " )";
		return os;
	}
};

