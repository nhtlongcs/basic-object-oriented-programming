#include <iostream>
#include <string>
#include <assert.h>
#include "fraction.h"

class RandomFractionGenerator
{
private:
    inline static RandomFractionGenerator *_instance = NULL;

private:
    RandomFractionGenerator()
    {
        srand(time(NULL));
    }
    // Private so that it can  not be called
    RandomFractionGenerator(RandomFractionGenerator const &){}; // copy constructor is private
    RandomFractionGenerator &operator=(RandomFractionGenerator const &)
    {
        return *this;
    }; // assignment operator is private

public:
    static RandomFractionGenerator *getInstance()
    {
        if (_instance == NULL)
        {
            _instance = new RandomFractionGenerator();
        }

        return _instance;
    }
    ~RandomFractionGenerator()
    {
        delete _instance;
    };

public:
    Fraction next();
    Fraction next(Fraction range);
    Fraction next(Fraction min, Fraction max);
};
Fraction RandomFractionGenerator::next()
{
    return Fraction::rand(100, 20);
}
