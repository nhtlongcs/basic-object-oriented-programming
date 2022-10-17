#include <iostream>

const int MAX_N = 1000;

// Some input functions
class Fraction
{
public:
    int numerator;
    int denominator;
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    Fraction()
    {
        this->numerator = 0;
        this->denominator = 0;
    }
    std::string toString()
    {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }
    Fraction parse(std::string text)
    {

        int pos = text.find("/");
        int numerator = std::stoi(text.substr(0, pos));
        int denominator = std::stoi(text.substr(pos + 1));
        return Fraction(numerator, denominator);
    }
    static bool cmpSmaller(const Fraction &u, const Fraction &v)
    {
        return u.numerator * v.denominator < v.numerator * u.denominator;
    }
    static bool cmpGreater(const Fraction &u, const Fraction &v)
    {
        return u.numerator * v.denominator > v.numerator * u.denominator;
    }
};
void readInt(int &x)
{
    std::cin >> x;
}

void readFraction(Fraction &u)
{
    // read fraction using Fraction parse
    std::string text;
    std::cin >> text;
    u = u.parse(text);
}
// Some compare functions
bool compareIntSmaller(const int &a, const int &b)
{
    return (a < b);
}
// Some compare functions
bool compareIntGreater(const int &a, const int &b)
{
    return (a > b);
}
// Some output functions
void writeInt(int &x)
{
    std::cout << x << ' ';
}
void writeFraction(Fraction &u)
{
    std::cout << u.toString() << ' ';
}

// General input, sort and output functions
template <class T>
void readData(int &n, T *a, void (*readElement)(T &))
{
    std::cout << "Enter n: ";
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cout << "Enter element " << i << ": ";
        readElement(a[i]);
    }
    std::cout << std::endl;
}

template <class T>
void sortArray(int &n, T *a, bool (*compareElement)(const T &, const T &))
{
    for (int i = 1; i <= n - 1; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (compareElement(a[j], a[i]))
            {
                T c = a[i];
                a[i] = a[j];
                a[j] = c;
            }
}

template <class T>
void writeData(int &n, T *a, void (*writeElement)(T &))
{
    std::cout << "Sorted array: ";
    for (int i = 1; i <= n; ++i)
        writeElement(a[i]);
}
int main()
{

    // Example of Int array
    std::cout << "Example of Int array" << std::endl;
    int n;
    int a[MAX_N];
    std::cout << "Please input your array: " << std::endl;
    readData(n, a, readInt);
    sortArray(n, a, compareIntSmaller);
    writeData(n, a, writeInt);
    std::cout << std::endl;
    sortArray(n, a, compareIntGreater);
    writeData(n, a, writeInt);
    std::cout << std::endl;

    // Example of Fraction array
    std::cout << "Example of Fraction array" << std::endl;
    int m;
    Fraction b[MAX_N];
    std::cout << "Please input your array: " << std::endl;
    readData(m, b, readFraction);
    sortArray(m, b, Fraction::cmpSmaller);
    writeData(m, b, writeFraction);
    std::cout << std::endl;
    sortArray(m, b, Fraction::cmpGreater);
    writeData(m, b, writeFraction);
    std::cout << std::endl;
    return 0;
}