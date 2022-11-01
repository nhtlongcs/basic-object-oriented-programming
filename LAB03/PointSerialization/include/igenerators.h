
#include <iostream>
#include <string>
#include <assert.h>

#ifndef IGENERATORS_H
#define IGENERATORS_H

class RandomIntegerGenerator
{
private:
    inline static RandomIntegerGenerator *_instance = NULL;

private:
    RandomIntegerGenerator()
    {
        srand(time(NULL));
    }
    // Private so that it can  not be called
    RandomIntegerGenerator(RandomIntegerGenerator const &){}; // copy constructor is private
    RandomIntegerGenerator &operator=(RandomIntegerGenerator const &)
    {
        return *this;
    }; // assignment operator is private

public:
    static RandomIntegerGenerator *getInstance()
    {
        if (_instance == NULL)
        {
            _instance = new RandomIntegerGenerator();
        }

        return _instance;
    }
    ~RandomIntegerGenerator()
    {
        delete _instance;
    };

public:
    int next() { return rand(); }
    int next(int range) { return rand() % range; }
    int next(int min, int max) { return min + rand() % (max - min); }
};
#endif