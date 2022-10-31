#include <iostream>
#include "Shape.h"
using namespace std;
void Print(Shape **a, int n)
{
	for (int i = 0; i < 5; ++i)
		a[i]->Print();
}
int main()
{
	Shape *a[5];
	int n = 5;
	a[0] = new Triangle(Point(1, 2), Point(2, 3), Point(3, 1));
	a[1] = new Rectangle(Point(3, 3), Point(5, 1));
	a[2] = new Circle(Point(2, 1), 3.1412);
	a[3] = new Triangle(Point(0, 0), Point(1, 1), Point(1, 0));
	a[4] = new Circle(Point(4, 1.5), 5.2);
	Print(a, n);
	for (int i = 0; i < 5; ++i)
		delete a[i];

	return 0;
}