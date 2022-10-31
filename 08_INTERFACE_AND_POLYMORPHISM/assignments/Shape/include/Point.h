#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;
class Point
{
	double m_x, m_y;

public:
	Point()
	{
		m_x = 0;
		m_y = 0;
	};
	Point(double x, double y)
	{
		m_x = x;
		m_y = y;
	}
	void Show()
	{
		cout << "(" << m_x << " , " << m_y << ")";
	}
	~Point(){};
};

#endif