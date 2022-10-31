#ifndef HORSE_H
#define HORSE_H

#include <string>
#include <iostream>
#include "base.h"
using namespace std;

class Horse : public Racer
{
private:
    string m_name;
    int m_veclocity;

public:
    Horse()
    {
        m_name = "Horse";
        m_veclocity = 60;
    };
    virtual ~Horse(){};
    string getName()
    {
        return m_name;
    }
    int getV()
    {
        return m_veclocity;
    }
};
#endif