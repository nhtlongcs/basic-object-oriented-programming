#include <iostream>
#include <fraction.h>
#include <error.h>
#include <logger.h>
#include <fstream>
#include "darray.h"

using namespace std;

Error *e;
Logger *l;
inline bool exists(const std::string &name)
{
    ifstream f(name.c_str());
    return f.good();
}

DynamicArray<Fraction> parseFractionFromFile(const std::string &filename)
{

    e = &Error::getInstance();
    l = &Logger::getInstance();

    DynamicArray<Fraction> fractions_ls;
    if (!exists(filename))
    {
        e->setErrorCode(ErrorCode::FileNotFound);
        string log = "Error: " + e->getErrorMessage();
        l->error(log);
        return fractions_ls;
    }
    std::ifstream file(filename);
    std::string line;
    int n = 0;
    std::getline(file, line);
    n = std::stoi(line);
    cout << "Expecting to have " << n << " fractions\n";
    for (std::string line; std::getline(file, line);)
    {
        Fraction item = Fraction::parse_safe(line);
        if (e->getErrorCode() == ErrorCode::OK)
        {
            fractions_ls.push_back(item);
        }
        else
        {
            string log = "Error: " + e->getErrorMessage();
            l->error(log);
        }
    }
    return fractions_ls;
}
void example()
{
    // Working with dynamic array of fractions from file

    // Reading input: fractions.txt
    // Expecting to have 5 fractions

    // Found 4 fractions: 1 1/2, 2, 1 1/6, 15/17

    DynamicArray<Fraction> fraction_ls;
    cout << "Working with dynamic array of fractions from file" << endl;
    cout << "Reading input: data/data.txt" << endl;
    fraction_ls = parseFractionFromFile("data/data.txt");
    if (e->getErrorCode() == ErrorCode::FileNotFound)
    {
        l->error("Exiting the program.");
        return;
    }
    if (e->getErrorCode() == ErrorCode::OK)
    {
        cout << "Found " << fraction_ls.size() << " fractions: ";
        for (int i = 0; i < fraction_ls.size(); i++)
        {
            cout << fraction_ls[i].lowest_terms().toString() << ", ";
        }
    }
    else
    {
        l->error("Error: " + e->getErrorMessage());
    }
}
int main()
{
    example();
    return 0;
}