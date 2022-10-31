#ifndef INTKEYBOARD_H
#define INTKEYBOARD_H

#include "error.h"
#include <iostream>
#include <vector>
#include <string>
#include "logger.h"
using namespace std;
class IntegersFromKeyboard
{
private:
    int size;
    vector<int> numbers;
    Error *e;
    Logger *l;

public:
    IntegersFromKeyboard();
    void found(string _typename, vector<int> number, bool (IntegersFromKeyboard::*predicate)(int));
    void excute();

    int read_safe(int lower, int upper);

    bool odd(int number);
    bool even(int number);
    bool palindromic(int number);
    bool prime(int number);
};
#endif