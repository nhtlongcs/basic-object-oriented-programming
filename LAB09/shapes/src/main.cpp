#include <regex>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "error.h"
#include "logger.h"

using namespace std;

Logger *logger = &Logger::getInstance();
Error *error = &Error::getInstance();

namespace Utils
{
    class String
    {
    public:
        static vector<string> split(string haystack, string needle)
        {
            vector<string> result;
            int startPos = 0;
            size_t foundPos = haystack.find(needle, startPos);

            while (foundPos != string::npos)
            {
                int count = foundPos - startPos;
                string token = haystack.substr(startPos, count);
                result.push_back(token);

                startPos = foundPos + needle.length();
                foundPos = haystack.find(needle, startPos);
            }

            // The remaining
            string token = haystack.substr(startPos, haystack.length() - startPos);
            result.push_back(token);

            return result;
        }
    };
}

class IShape
{
public:
    virtual double area(){};
    virtual double perimeter(){};
    virtual string toString()
    {
        return "IShape";
    }
    ~IShape() = default;
};

class IParsable
{
public:
    IParsable()
    {
        logger->debug("IParsable::IParsable() is called");
    }
    virtual string parsedObjectName() = 0;
    virtual IShape *parse(string line) = 0;
    ~IParsable() = default;
};
class Square : public IShape
{
private:
    double _a;

public:
    Square(double a)
    {
        _a = a;
    }
    double area()
    {
        return _a * _a;
    }
    double perimeter()
    {
        return 4 * _a;
    }
    string toString()
    {
        return "Square";
    }
    ~Square()
    {
        cout << "Square is destroyed" << endl;
    }
};
class Circle : public IShape
{
private:
    double _r;

public:
    Circle(double r)
    {
        _r = r;
    }
    double area()
    {
        return 3.14 * _r * _r;
    }
    double perimeter()
    {
        return 2 * 3.14 * _r;
    }
    string toString()
    {
        return "Circle";
    }
    ~Circle()
    {
        cout << "Circle is destroyed" << endl;
    }
};
class Rectangle : public IShape
{
private:
    double _w, _h;

public:
    Rectangle(double w, double h)
    {
        _w = w;
        _h = h;
    }
    double area()
    {
        return _w * _h;
    }
    double perimeter()
    {
        return 2 * (_w + _h);
    }
    string toString()
    {
        return "Rectangle";
    }
    ~Rectangle()
    {
        cout << "Rectangle is destroyed" << endl;
    }
};
class SquareParser : public IParsable
{
public:
    SquareParser() : IParsable()
    {
        logger->debug("SquareParser::SquareParser() is called");
    }
    string parsedObjectName()
    {
        return "Square";
    }
    IShape *parse(string line)
    {
        logger->debug("SquareParser::parse() is called");
        logger->debug("line: " + line);
        vector<string> tokens = Utils::String::split(line, "=");
        logger->debug("tokens[1]: " + tokens[1]);
        double a = stod(tokens[1]);
        return new Square(a);
    }
    ~SquareParser()
    {
        cout << "SquareParser is destroyed" << endl;
    }
};
class CircleParser : public IParsable
{
public:
    CircleParser() : IParsable()
    {
        logger->debug("CircleParser::CircleParser() is called");
    }
    string parsedObjectName()
    {
        return "Circle";
    }
    IShape *parse(string line)
    {
        logger->debug("CircleParser::parse() is called");
        vector<string> tokens = Utils::String::split(line, "=");
        double r = stod(tokens[1]);
        return new Circle(r);
    }
    ~CircleParser()
    {
        cout << "CircleParser is destroyed" << endl;
    }
};
class RectangleParser : public IParsable
{
public:
    RectangleParser() : IParsable()
    {
        logger->debug("RectangleParser::RectangleParser() is called");
    }
    string parsedObjectName()
    {
        return "Rectangle";
    }
    IShape *parse(string line)
    {
        logger->debug("RectangleParser::parse() is called");
        string pattern = "Rectangle w=(\\d+), h=(\\d+)";
        regex re(pattern);
        smatch match;
        regex_search(line, match, re);
        logger->debug("match[1]: " + match.str(1));
        double w = stod(match.str(1));
        double h = stod(match.str(2));
        return new Rectangle(w, h);
    }
    ~RectangleParser()
    {
        cout << "RectangleParser is destroyed" << endl;
    }
};
class ParserFactory
{
public:
    map<string, IParsable *> _container; // A container for all the dependencies injection
public:
    void registerWith(IParsable *parser)
    { // Do the injection here
        _container.insert(
            {parser->parsedObjectName(), parser});
    }

    IParsable *create(string type)
    {
        logger->debug("ParserFactory::create() is called");
        logger->debug("type = " + type);
        return _container[type]; // Ask container to resolve the needed type
    }
    ~ParserFactory()
    {
        for (auto it = _container.begin(); it != _container.end(); it++)
        {
            delete it->second;
        }
    }
};
int main()
{
    ParserFactory factory;
    factory.registerWith(new SquareParser());
    factory.registerWith(new CircleParser());
    factory.registerWith(new RectangleParser());
    vector<string> lines = {
        "Square a=12",
        "Circle r=12",
        "Square a=7",
        "Rectangle w=3, h=4",
        "Rectangle w=6, h=8",
        "Circle r=5",
        "Square a=8"};

    vector<IShape *> shapes;
    for (string line : lines)
    {
        // Example: line = "Square a=12"
        vector<string> tokens = Utils::String::split(line, " ");
        IParsable *parser = factory.create(tokens[0]);               // "Square"=> SquareParser
        IShape *shape = dynamic_cast<IShape *>(parser->parse(line)); // "Square a=12" => Square
        shapes.push_back(shape);
    }

    for (IShape *shape : shapes)
    { // Polymorphism
        cout << shape->toString() << ": area="
             << shape->area() << ", perimeter="
             << shape->perimeter() << endl;
    }
}