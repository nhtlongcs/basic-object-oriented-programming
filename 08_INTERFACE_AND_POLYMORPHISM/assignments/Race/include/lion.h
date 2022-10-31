#ifndef LION_H
#define LION_H

#include <string>
#include <iostream>
#include "base.h"
using namespace std;

class Lion : public Racer
{
private:
    string m_name;
    int m_veclocity;

public:
    Lion()
    {
        m_name = "Lion";
        m_veclocity = 70;
    };
    virtual ~Lion(){};
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