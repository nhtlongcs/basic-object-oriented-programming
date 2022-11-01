#include <iostream>
#include <fraction.h>
#include <error.h>
#include <logger.h>
#include <fstream>

using namespace std;

Error *e;
Logger *l;
inline bool exists(const std::string &name)
{
    ifstream f(name.c_str());
    return f.good();
}

vector<Fraction> parseFractionFromFile(const std::string &filename)
{

    e = &Error::getInstance();
    l = &Logger::getInstance();

    vector<Fraction> fractions_ls;
    if (!exists(filename))
    {
        e->setErrorCode(ErrorCode::FileNotFound);
        string log = "Error: " + e->getErrorMessage();
        l->error(log);
        return fractions_ls;
    }
    std::ifstream file(filename);
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
    // Fraction deserialization

    // Reading fractions from data.txt file...
    // Found 5 fractions: 3/7, 5 1/2, 1 1/2, 25, 3 1/2
    // The sum of all fractions is: 35 13/14

    vector<Fraction> fraction_ls;
    cout << "Reading fractions from data.txt file..." << endl;
    fraction_ls = parseFractionFromFile("data/data.txt");
    if (e->getErrorCode() == ErrorCode::FileNotFound)
    {
        l->error("Exiting the program.");
        return;
    }
    if (e->getErrorCode() == ErrorCode::OK)
    {
        cout << "Found " << fraction_ls.size() << " fractions: ";
        for (Fraction f : fraction_ls)
        {
            cout << f.toString() << ", ";
        }
        cout << endl;
        Fraction sum = Fraction(0, 1);
        for (Fraction f : fraction_ls)
        {
            sum = sum + f;
        }
        cout << "The sum of all fractions is: " << sum.toString() << endl;
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