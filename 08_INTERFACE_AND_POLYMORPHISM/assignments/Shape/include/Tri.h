#ifndef TRI_H
#define TRI_H
#include "Shape.h"

using namespace std;
class Triangle : public Shape
{
private:
    Point m_a, m_b, m_c;

public:
    Triangle(){};
    Triangle(Point a, Point b, Point c)
    {
        m_a = a;
        m_b = b;
        m_c = c;
    };
    virtual ~Triangle(){};
    void Print()
    {
        cout << "(";
        m_a.Show();
        cout << ",";
        m_b.Show();
        cout << ",";
        m_c.Show();
        cout << ")\n";
    }
};

#endif