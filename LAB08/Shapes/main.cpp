#include <iostream>
#include <vector>

using namespace std;

class Shape
{
public:
    virtual string toString() = 0;
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class Rectangle : public Shape
{
public:
    int width, height;
    Rectangle(int width, int height)
    {
        this->width = width;
        this->height = height;
    }
    string toString()
    {
        return "Rectangle w=" + to_string(width) + ", h=" + to_string(height);
    }
    double area()
    {
        return width * height;
    }
    double perimeter()
    {
        return 2 * (width + height);
    }
};

class Square : public Rectangle
{
public:
    int side;
    Square(int side) : Rectangle(side, side)
    {
        this->side = side;
    }
    string toString()
    {
        return "Square a=" + to_string(side);
    }
};

class Circle : public Shape
{
public:
    double radius;
    Circle(double radius)
    {
        this->radius = radius;
    }
    string toString()
    {
        return "Circle r=" + to_string(radius);
    }
    double area()
    {
        return 3.14 * radius * radius;
    }
    double perimeter()
    {
        return 2 * 3.14 * radius;
    }
};

int main()
{
    // Rectangle w=4, h=7: area=28, perimeter=22
    // Rectangle w=6, h=8: area=48, perimeter=28
    // Rectangle w=3, h=2: area=6, perimeter=10
    // Square a=7: area=49, perimeter=28
    // Square a=6: area=36, perimeter=24
    // Square a=9: area=81, perimeter=36
    // Circle r=4.3, area=58.0586, perimeter=27.004
    // Circle r=5.5, area=94.985, perimeter=34.54
    // Circle r=6.2, area=128.4888, perimeter=38.936
    vector<Rectangle *> rectangles = {
        new Rectangle(4, 7), // width + height
        new Rectangle(6, 8),
        new Rectangle(3, 2)};

    for (Rectangle *shape : rectangles)
    {
        cout << shape->toString() << ": "
             << "area=" << shape->area() << ", perimeter=" << shape->perimeter()
             << endl;
    }

    vector<Square *> squares = {
        new Square(7),
        new Square(6),
        new Square(9)};

    for (Square *shape : squares)
    {
        cout << shape->toString() << ": "
             << "area=" << shape->area() << ", perimeter=" << shape->perimeter()
             << endl;
    }

    vector<Circle *> circles = {
        new Circle(4.3), // radius
        new Circle(5.5),
        new Circle(6.2)};

    for (Circle *shape : circles)
    {
        cout << shape->toString() << ": "
             << "area=" << shape->area() << ", perimeter=" << shape->perimeter()
             << endl;
    }
}