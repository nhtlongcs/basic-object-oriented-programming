#ifndef REC_H
#define REC_H
#include "Shape.h"

using namespace std;
class Rectangle : public Shape
{
private:
    Point m_topLeft, m_bottomRight;

public:
    Rectangle(){};
    Rectangle(const Point &a, const Point &b)
    {
        m_topLeft = a;
        m_bottomRight = b;
    };
    virtual ~Rectangle(){};
    void Print()
    {
        cout << "(";
        m_topLeft.Show();
        cout << ",";
        m_bottomRight.Show();
        cout << ")\n";
    }
};

#endif