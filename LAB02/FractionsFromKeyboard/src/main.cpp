#include <iostream>
#include <vector>
#include <string>
#include "logger.h"
#include "error.h"
#include "fraction.h"
#include "igenerators.h"
using namespace std;
void example()
{
    // Working with fractions from the keyboard

    // Please enter 6 fractions.
    // Fraction [0]: 1/8
    // Fraction [1]: 2/8
    // Fraction [2]: 3/8
    // Fraction [3]: 4/8
    // Fraction [4]: 5/8
    // Fraction [5]: 6/8

    // The sum of all fractions is: 2 5/8

    Error *e;
    Logger *l;
    RandomIntegerGenerator *generator = RandomIntegerGenerator::getInstance();
    vector<Fraction> fractions;
    Fraction sum = Fraction(0, 1);

    e = &Error::getInstance();
    l = &Logger::getInstance();
    int N = generator->next(5, 10);
    cout << "Working with fractions from the keyboard" << endl;
    cout << "Please enter " << N << " fractions." << endl;
    for (int i = 0; i < N; i++)
    {
        // loop until the user enters a valid number
        do
        {
            Fraction value;
            cout << "Fraction [" << i << "]: ";
            value = Fraction::read_safe(1, 100); // lower and upper bounds
            if (e->getErrorCode() == ErrorCode::OK)
            {
                fractions.push_back(value);
                sum = sum + value;
                cout << endl;
            }
            else
            {
                string log = "Error: " + e->getErrorMessage();
                l->error(log);
            }
        } while (e->getErrorCode() != ErrorCode::OK);
    }
    cout << "The sum of all fractions is: " << sum.toString() << endl;
}

int main()
{
    example();
    return 0;
}