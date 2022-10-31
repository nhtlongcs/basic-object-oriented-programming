#ifndef DOG_H
#define DOG_H

#include <string>
#include <iostream>
#include "base.h"
using namespace std;

class Dog : public Racer
{
private:
    string m_name;
    int m_veclocity;

public:
    Dog()
    {
        m_name = "Dog";
        m_veclocity = 60;
    };
    virtual ~Dog(){};
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