#ifndef RANDOMINTKEYBOARD_H
#define RANDOMINTKEYBOARD_H

#include "error.h"
#include <iostream>
#include <vector>
#include <string>
#include "logger.h"
#include <cmath>
using namespace std;
class RandomlyGeneratedIntegers
{
private:
    int size;
    vector<int> numbers;
    Error *e;
    Logger *l;

public:
    RandomlyGeneratedIntegers();
    void found(string _typename, vector<int> number, bool (RandomlyGeneratedIntegers::*predicate)(int));
    void excute();
    int gen(int lower, int upper);

    int read_safe(int lower, int upper);

    bool odd(int number);
    bool even(int number);
    bool palindromic(int number);
    bool square(int number);
};
#endif