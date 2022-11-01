#include <iostream>
#include <vector>
#include "fraction.h"
#include "fgenerators.h"
using namespace std;
void example()
{
    // Random fraction generator

    // Generating 6 fractions: 4/2, 14/4, 8/10, 7/2, 1/3, 2/4
    // Fractions in their lowest term: 2, 3 1/2, 4/5, 1/3, 1/2
    // Fractions in their decimal form: 2.000, 3.500, 0.800, 0.333, 0.500
    // Fractions in their percentage form: 200.00%, 3500.00%, 33.33%, 50.00%
    RandomFractionGenerator *generator = RandomFractionGenerator::getInstance();
    vector<Fraction> fractions;
    int N = 6;
    cout << "Generating 6 fractions: ";
    for (int i = 0; i < N; i++)
    {
        fractions.push_back(generator->next());
        cout << fractions[i].toString() << ", ";
    }
    cout << endl;
    cout << "Fractions in their lowest term: ";
    for (int i = 0; i < N; i++)
    {
        cout << fractions[i].lowest_terms().toString() << ", ";
    }
    cout << endl;
    cout << "Fractions in their decimal form: ";
    for (int i = 0; i < N; i++)
    {
        cout << fractions[i].toDouble() << ", ";
    }
    cout << endl;
    cout << "Fractions in their percentage form: ";
    for (int i = 0; i < N; i++)
    {
        cout << fractions[i].percentage() << ", ";
    }
    cout << endl;
}

int main()
{
    example();
    return 0;
}