#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"
class Shape
{
public:
	virtual void Print() = 0;
	Shape(){};
	virtual ~Shape(){};
};

#endif