#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include <iostream>
#include "base.h"
using namespace std;

class Human : public Racer
{
private:
    string m_name;
    int m_veclocity;

public:
    Human()
    {
        m_name = "Human";
        m_veclocity = 30;
    };
    virtual ~Human(){};
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