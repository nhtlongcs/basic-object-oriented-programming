#include <iostream>
#include "Triangle.h"
int main()
{
	Triangle T(Point(-5, 29), Point(20, 30), Point(-3, -50));
	cout << T << "\n";
	cout << T.getArea() << "\n";
	cout << T.getPerimeter() << "\n";
	cout << T.getCentroid() << "\n";
	cout << T.getMidPer() << "\n";
	cout << T.getCenter() << "\n";
	return 0;
}