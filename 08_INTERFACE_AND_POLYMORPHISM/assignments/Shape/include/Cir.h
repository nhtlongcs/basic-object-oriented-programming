#ifndef CIR_H
#define CIR_H
#include "Shape.h"

using namespace std;

class Circle : public Shape
{
private:
    Point m_center;
    double m_radius;

public:
    Circle(Point center, double r)
    {
        m_center = center;
        m_radius = r;
    };
    virtual ~Circle(){};
    void Print()
    {
        cout << "(";
        m_center.Show();
        cout << ",";
        cout << m_radius;
        cout << ")\n";
    }
};
#endif