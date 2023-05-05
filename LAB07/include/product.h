#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <regex>
#include "logger.h"
#include "error.h"
using namespace std;


class Price
{
public:
    int value;

public:
    Price() {}
    Price(int price)
    {
        this->value = price;
    }
    string toString()
    {
        // convert value to currency string
        string str = to_string(value);
        int len = str.length();
        int i = 0;
        while (i < len - 3)
        {
            str.insert(len - 3 - i, ".");
            i += 3;
        }
        return str;
    }
};

class Product
{
public:
    int id;
    string name;
    Price price;

public:
    Product(){};
    Product(int id, string name, Price price)
    {
        this->id = id;
        this->name = name;
        this->price = price;
    }
    string toString()
    {
        return "ID: " + to_string(id) + ", Name: " + name + ", Price: " + price.toString() + " d";
    }
    string toExportString()
    {
        return "ID=" + to_string(id) + ", Name=" + name + ", Price=" + std::to_string(price.value);
    }
};
#endif