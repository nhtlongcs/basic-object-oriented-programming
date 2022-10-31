#ifndef CHEETAH_H
#define CHEETAH_H

#include <string>
#include <iostream>
#include "base.h"
using namespace std;

class Cheetah : public Racer
{
private:
    string m_name;
    int m_veclocity;

public:
    Cheetah()
    {
        m_name = "Cheetah";
        m_veclocity = 100;
    };
    virtual ~Cheetah(){};
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