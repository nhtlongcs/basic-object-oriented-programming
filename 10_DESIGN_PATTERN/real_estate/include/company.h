#include <iostream>
#include <vector>
#include "land.h"
#include "factory.h"
#ifndef COMPANY_H
#define COMPANY_H

class Company
{
public:
    Company();
    ~Company(){};
    void readData();
    void printData();

private:
    int totalArea, totalPrice;
    LandFactory<int, UPTRB> factory;
    std::vector<UPTRB> lands;
};
Company::Company()
{
    factory.add(1, createClass<RectLand, string, int, int, int>);
    factory.add(2, createClass<TrapezoidLand, string, int, int, int, int>);
}
void Company::readData()
{
    cout << "Please input the number of lands: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Please input the type of land (1: RectLand, 2: TrapezoidLand): ";
        int type;
        cin >> type;
        cout << "Please input the id: ";
        string id;
        int pricePerUnit;
        cin >> id;
        cout << "Please input the price per unit: ";
        cin >> pricePerUnit;
        if (type == 1)
        {
            cout << "Please input the width and length: ";
            int width, length;
            cin >> width >> length;
            lands.push_back(factory.create(1, id, pricePerUnit, width, length));
        }
        else if (type == 2)
        {
            cout << "Please input the upper base, lower base and height: ";
            int upper, lower, height;
            cin >> upper >> lower >> height;
            lands.push_back(factory.create(2, id, pricePerUnit, upper, lower, height));
        }
    }
}
void Company::printData()
{
    totalArea = 0;
    totalPrice = 0;
    for (int i = 0; i < lands.size(); i++)
    {
        lands[i]->printData();
        totalArea += lands[i]->area;
        totalPrice += lands[i]->calcPrice();
    }
    cout << "Total area: " << totalArea << endl;
    cout << "Total price: " << totalPrice << endl;
}
#endif