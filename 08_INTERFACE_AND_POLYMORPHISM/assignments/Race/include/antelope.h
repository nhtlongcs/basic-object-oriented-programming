#ifndef ANTE_H
#define ANTE_H

#include <string>
#include <iostream>
#include "base.h"
using namespace std;

class Antelope : public Racer
{
private:
    string m_name;
    int m_veclocity;

public:
    Antelope()
    {
        m_name = "Linh Duong";
        m_veclocity = 80;
    };
    virtual ~Antelope(){};
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