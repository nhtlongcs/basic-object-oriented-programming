#include <iostream>
#include <string>
#include <assert.h>
#include "point.h"

class RandomPointGenerator
{
private:
    inline static RandomPointGenerator *_instance = NULL;

private:
    RandomPointGenerator()
    {
        srand(time(NULL));
    }
    // Private so that it can  not be called
    RandomPointGenerator(RandomPointGenerator const &){}; // copy constructor is private
    RandomPointGenerator &operator=(RandomPointGenerator const &)
    {
        return *this;
    }; // assignment operator is private

public:
    static RandomPointGenerator *getInstance()
    {
        if (_instance == NULL)
        {
            _instance = new RandomPointGenerator();
        }

        return _instance;
    }
    ~RandomPointGenerator()
    {
        delete _instance;
    };

public:
    Point next();
    Point next(int x_range, int y_range);
};
Point RandomPointGenerator::next()
{
    return Point::rand();
}
Point RandomPointGenerator::next(int x_range, int y_range)
{
    return Point::rand(x_range, y_range);
}