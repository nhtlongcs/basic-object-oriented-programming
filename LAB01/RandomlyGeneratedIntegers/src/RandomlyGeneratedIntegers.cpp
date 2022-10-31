#include "RandomlyGeneratedIntegers.h"

int RandomlyGeneratedIntegers::read_safe(int min, int max)
{
    e = &Error::getInstance();
    string buffer;
    int number = 0;
    e->setErrorCode(ErrorCode::OK);
    getline(cin, buffer);
    if (buffer == "")
    {
        e->setErrorCode(ErrorCode::EmptyInput);
        return -1;
    }
    try
    {
        number = stoi(buffer);
    }
    catch (...)
    {
        e->setErrorCode(ErrorCode::InvalidFormat);
    }
    if (e->getErrorCode() != ErrorCode::OK)
        return -1;
    if (number < min || number > max)
    {
        e->setErrorCode(ErrorCode::OutOfRange);
        return -1;
    }
    e->setErrorCode(ErrorCode::OK);
    return number;
}
RandomlyGeneratedIntegers::RandomlyGeneratedIntegers()
{
    e = &Error::getInstance();
    l = &Logger::getInstance();

    cout << "Working with randomly generated integers " << endl;
    size = gen(5, 10);
    for (int i = 0; i < size; i++)
    {
        int value;
        value = gen(10, 100);
        numbers.push_back(value);
    }
    cout << "Generating ";
    string log = to_string(this->size) + " integer(s):";
    l->log(log, Color::Red);
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
}
bool RandomlyGeneratedIntegers::odd(int number)
{
    return number % 2 != 0;
}
bool RandomlyGeneratedIntegers::even(int number)
{
    return number % 2 == 0;
}
bool RandomlyGeneratedIntegers::palindromic(int number)
{
    string numberString = to_string(number);
    int length = numberString.length();
    for (int i = 0; i < length / 2; i++)
    {
        if (numberString[i] != numberString[length - i - 1])
        {
            return false;
        }
    }
    return true;
}
int RandomlyGeneratedIntegers::gen(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
bool RandomlyGeneratedIntegers::square(int number)
{
    int squareRoot = sqrt(number);
    return squareRoot * squareRoot == number;
}
void RandomlyGeneratedIntegers::found(string _typename, vector<int> number, bool (RandomlyGeneratedIntegers::*predicate)(int))
{
    vector<int> foundNumbers;
    for (int i = 0; i < size; i++)
        if ((this->*predicate)(numbers[i]))
            foundNumbers.push_back(numbers[i]);
    cout << "Found ";
    string log = to_string(foundNumbers.size()) + " " + _typename + " numbers: ";
    l = &Logger::getInstance();
    l->log(log, Color::Red);
    for (int i = 0; i < foundNumbers.size(); i++)
        cout << foundNumbers[i] << " ";
    cout << endl;
}
void RandomlyGeneratedIntegers::excute()
{
    found("odd", numbers, &RandomlyGeneratedIntegers::odd);
    found("even", numbers, &RandomlyGeneratedIntegers::even);
    found("palindrom", numbers, &RandomlyGeneratedIntegers::palindromic);
    found("square", numbers, &RandomlyGeneratedIntegers::square);
}