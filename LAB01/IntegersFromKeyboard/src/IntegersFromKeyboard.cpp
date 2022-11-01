#include "IntegersFromKeyboard.h"

int IntegersFromKeyboard::read_safe(int min, int max)
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

    string pattern = "\\d+"; // \d: digits only 0-9, +: one or more
    bool matched = regex_match(buffer, regex(pattern));
    if (!matched)
    {
        e->setErrorCode(ErrorCode::InvalidFormat);
        return -1;
    }
    number = stoi(buffer);
    if (number < min || number > max)
    {
        e->setErrorCode(ErrorCode::OutOfRange);
        return -1;
    }
    e->setErrorCode(ErrorCode::OK);
    return number;
}
IntegersFromKeyboard::IntegersFromKeyboard()
{
    e = &Error::getInstance();
    l = &Logger::getInstance();

    cout << "Working with integer arrays from the keyboard" << endl;
    cout << "Please enter an integer in the range of [5, 10]: ";
    cin >> this->size;
    cout << "Please enter " << this->size << " integer(s), each in the range of [1, 100]: " << endl;
    for (int i = 0; i < size; i++)
    {
        // loop until the user enters a valid number
        do
        {
            int value;
            cout << "The [" << i << "] integer: ";
            value = read_safe(1, 100); // lower and upper bounds
            if (e->getErrorCode() == ErrorCode::OK)
            {
                numbers.push_back(value);
                cout << endl;
            }
            else
            {
                string log = "Error: " + e->getErrorMessage();
                l->error(log);
            }
        } while (e->getErrorCode() != ErrorCode::OK);
    }
    cout << "You have entered ";
    string log = to_string(this->size) + " integer(s):";
    l->log(log, Color::Red);
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
}
bool IntegersFromKeyboard::odd(int number)
{
    return number % 2 != 0;
}
bool IntegersFromKeyboard::even(int number)
{
    return number % 2 == 0;
}
bool IntegersFromKeyboard::palindromic(int number)
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
bool IntegersFromKeyboard::prime(int number)
{
    if (number == 1)
    {
        return false;
    }
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
void IntegersFromKeyboard::found(string _typename, vector<int> number, bool (IntegersFromKeyboard::*predicate)(int))
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
void IntegersFromKeyboard::excute()
{
    found("odd", numbers, &IntegersFromKeyboard::odd);
    found("even", numbers, &IntegersFromKeyboard::even);
    found("palindrom", numbers, &IntegersFromKeyboard::palindromic);
    found("prime", numbers, &IntegersFromKeyboard::prime);
}