#include <iostream>
#include <string>
#ifndef LAND_H
#define LAND_H
using namespace std;
class Land
{
public:
    Land() {}
    Land(string id, int pricePerUnit)
    {
        this->id = id;
        this->pricePerUnit = pricePerUnit;
    }
    virtual ~Land() {}
    virtual string get_id() = 0;
    virtual int calcPrice() = 0;
    virtual void printData() = 0;

protected:
    string id;
    int pricePerUnit;

public:
    int area;
};

class RectLand : public Land
{
private:
    int width;
    int length;

public:
    RectLand() {}
    RectLand(string id, int pricePerUnit, int width, int length)
        : Land(id, pricePerUnit)
    {
        this->width = width;
        this->length = length;
        this->area = width * length;
    }
    ~RectLand() {}
    string get_id() { return string{"Rect"}; }
    int calcPrice() { return area * pricePerUnit; }
    void printData() { std::cout << "RectLand [" << id << "], Area = " << area << std::endl; }
};

class TrapezoidLand : public Land
{
private:
    int upperBase;
    int lowerBase;
    int height;

public:
    TrapezoidLand() {}
    TrapezoidLand(string id, int pricePerUnit, int upper, int lower, int height)
        : Land(id, pricePerUnit)
    {
        this->upperBase = upper;
        this->lowerBase = lower;
        this->height = height;
        this->area = (upper + lower) * height / 2;
    }
    ~TrapezoidLand() {}
    string get_id() { return string{"TrapezoidLand"}; }
    int calcPrice() { return area * pricePerUnit * 0.95; }
    void printData() { std::cout << "TrapezoidLand [" << id << "], Area = " << area << std::endl; }
};

#endif