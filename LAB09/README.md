# Usage 

How to use the code

```bash
$ make main 
$ ./main
```

## 1. Working with shapes

- Name your project: **Shapes**
- Given the below main function, write all necessary files to make it run.

```cpp
int main() {
    vector<string> lines = {
        "Square a=12",
        "Circle r=12",
        "Square a=7",
        "Rectangle w=3, h=4",
        "Rectangle w=6, h=8",
        "Circle r=5",
        "Square a=8"
    };

    ParserFactory factory;
    vector<IShape*> shapes;

    for (string line : lines) {
				// Example: line = "Square a=12"
				vector<string> tokens = Utils::String::split(line, " ");
				IParsable* parser = factory.create(tokens[0]); // "Square"=> SquareParser
        IShape* shape = dynamic_cast<IShape*>(parser->parse(tokens[1])); // "a=12" => Square(_a = 12)
        shapes.push_back(shape);
    }

    for (IShape* shape : shapes) { // Polymorphism
        cout << shape->toString() << ": area=" 
            << shape->area() << ", perimeter=" 
            << shape->perimeter() << endl;
    }
}
```

Sample output

```cpp
Square a=12: area=144, perimeter=48
Circle r=12: area=432, perimeter=72
Square a=7: area=49, perimeter=28
Rectangle w=3, h=4: area=12, perimeter=14
Rectangle w=6, h=8: area=48, perimeter=28
Circle r=5: area=75, perimeter=30
Square a=8: area=64, perimeter=32
```

## Hints

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/9f024889-498d-4402-8f46-1f7b734b6ae8/Untitled.png)

```cpp
namespace Utils {
    class String {
    public:
        static vector<string> split(string haystack, string needle) {
            vector<string> result;
            int startPos = 0;
            size_t foundPos = haystack.find(needle, startPos);

            while (foundPos != string::npos) {
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
```

## Usage of ParserFactory

```cpp
ParserFactory factory;
string name = "Rectangle";
IParsable* parser = factory.create(name); // return new RectangleParser

name = "Circle";
parser = factory.create("Circle"); // return new CircleParser

name = "Square;
parser = factory.create("Circle"); // return new SquareParser
```

So basically, inside the create function is just a switch

```cpp
IParsable* ParserFactory::create(string type) {
    IParsable* parser = NULL;

    if ("Rectangle" == type) {
        parser = new RectangleParser();
    }
    else if ("Square" == type) {
        parser = new SquareParser();
    }
    else if ("Circle" == type) {
        parser = new CircleParser();
    }

    return parser;
}
```

Improvement **01** to make the code shorter and easier to read

```cpp
IParsable* ParserFactory::create(string type) {
		map<string, IParsable*> container = {
			{"Rectangle", new RectangleParser()},
			{"Square", new SquareParser()},
			{"Circle", new CircleParser()}
		}:
    IParsable* result = container [type];

    return parser;
}
```

Improvement **02** to make the code becomes more upgradable

```cpp
// Let use dependency injection
class ParserFactory {
private:
	map<string, IParsable*> _container; // A container for all the dependencies injection
public:
	void registerWith(IParsable* parser) { // Do the injection here 
		_container.insert(
			{parser->parsedObjectName(), parser}
		);
	}

	IParsable* create(string type) {
		return _container[type]; // Ask container to resolve the needed type
	}
}

int main() { // In the beginning of our application
	ParserFactory factory; // We inject what we want to work with here
	factory.registerWith(new RectangleParser());
	factory.registerWith(new SquareParser());
	factory.registerWith(new CirleParser());

	//...
}
```

## 2. Working with employees

- Name your project: **EmployeesPolymorphism**
- Given the below main function, write all necessary files to make it run.

```cpp
int main()
{
		ParserFactory factory;
    factory.registerWith(new DailyEmployeeParser());
    factory.registerWith(new ProductEmployeeParser());
    factory.registerWith(new ManagerParser());

    vector<string> lines = {
        "ProductEmployee productCount=790, paymentPerProduct=20000",
        "DailyEmployee dayCount=20, paymentPerPay=1000000",
        "ProductEmployee productCount=810, paymentPerProduct=19000",
        "ProductEmployee productCount=900, paymentPerProduct=18000",
        "Manager employeeCount=49, paymentPerEmployee=500000, baseSalary=6000000",
        "DailyEmployee dayCount=22, paymentPerPay=1100000",
        "Manager employeeCount=37, paymentPerEmployee=500000, baseSalary=7000000",
        "DailyEmployee dayCount=18, paymentPerPay=1500000",
        "Manager employeeCount=30, paymentPerEmployee=500000, baseSalary=5000000"
    };

    vector<Employee*> employees;

    for (string line : lines) {// "ProductEmployee productCount=790, paymentPerProduct=20000"
        int splitPosition = line.find_first_of(" ");
        string type = line.substr(0, splitPosition); // type = "ProductEmployee" 
        IParsable* parser = factory.create(type);   

			 // data = "productCount=790, paymentPerProduct=20000",
        string data = line.substr(splitPosition + 1, line.length() - splitPosition - 1);
        Employee* employee = dynamic_cast<Employee*>(parser->parse(data));
        employees.push_back(employee);
    }

    for (auto employee : employees) {
        cout << employee->toString() << ", salary:" << employee->salary() << endl;
    }
}
```

Sample output

```cpp
Product employee, salary:15.800.000 d
Daily employee, salary:20.000.000 d
Product employee, salary:15.390.000 d
Product employee, salary:16.200.000 d
Manager, salary:25.000.000 d
Daily employee, salary:24.200.000 d
Manager, salary:19.000.000 d
Daily employee, salary:27.000.000 d
Manager, salary:15.500.000 d
```

## Hints

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/5829f9ea-e07e-4047-ae3c-ead2a8301479/Untitled.png)

```cpp
class NumberFormatInfo: public Object {
private:
	string _currencyDecimalSeparator = ".";
	string _currencySymbol = "d";

	// https://stackoverflow.com/questions/17459450/how-to-determine-currency-symbol-position-for-a-culture
	int _currencyPositive = 3;				// 0		1		2		3
	string _currencyPositiveFormat = "n $"; // "$n"		"n$"	"$ n"	"n $"
public:
	string currencyDecimalSeparator();
	string currencySymbol();
	int currencyPositive();
	string currencyPositiveFormat();
public:
	string toString();
};
```

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4bac3c4c-ac0f-4488-a541-8917529ca7bd/Untitled.png)

```cpp
class ParserFactory: public Object {
private:
	map<string, IParsable*> _container;

public:
	void registerWith(IParsable* parser);
	IParsable* create(string type);
	string toString();
};

void ParserFactory::registerWith(IParsable* parser) {
	_container.insert({ parser->parsedObjectName(), parser });
}

IParsable* ParserFactory::create(string type) {
	return _container[type];
}
```

```cpp
class Integer: public Object {
private:
	int _value;
public:
	Integer();
	Integer(int);
	int value();
	string toString();
};
```

```cpp
Integer::Integer() {
	_value = 0;
}

Integer::Integer(int value) {
	_value = value;
}

string Integer::toString() {
	return "Integer";
}

int Integer::value() {
	return _value;
}
```

```cpp
string IntegerToCurrencyConverter::convert(Object* object) {
	auto number = dynamic_cast<Integer*>(object);
	int value = number->value();

	stringstream builder;
	NumberFormatInfo info;
	int count = 0;

	while (value != 0) {
		int lastDigit = value % 10;
		builder << lastDigit;

		count++;

		if (count == 3) {
			builder << info.currencyDecimalSeparator();
			count = 0;
		}

		value /= 10;
	}

	string numberSeparated = builder.str(); // "000.000.1"
	reverse(numberSeparated.begin(), numberSeparated.end());
	
	string format = info.currencyPositiveFormat(); "n $" ==> "1.000.000 d"
	string symbol = info.currencySymbol(); // "d"

	// https://stackoverflow.com/questions/17459450/how-to-determine-currency-symbol-position-for-a-culture
	string result = regex_replace(format, regex("n"), numberSeparated);
	result = regex_replace(result, regex("\\$"), symbol);

	return result;
}
```

## 3. Working with renaming rule

- Name your project: **RenamingRulesPolymorphism**
- Given the below main function, write all necessary files to make it run.

```cpp
int main() {
		ParserFactory factory;
	  factory.registerWith(new RemoveSpecialCharsParser());
	  factory.registerWith(new OneSpaceOnlyParser());
    factory.registerWith(new AddCurrentMonthParser());
    factory.registerWith(new AddPrefixParser());
    factory.registerWith(new ReplaceParser());

    vector<string> hrRules = {
        "RemoveSpecialChars blacklist=-_+",
        "OneSpaceOnly",
        "AddCurrentMonth",
        "AddPrefix CV",
        "Replace pattern=773423, to=devops"
    };

    vector<string> filenames = {
        "+++Cao---Minh----Long 773423.pdf",
        "Tran    Huu  Nhan 773423.pdf",
        "Do-Diem-Minh 773423.pdf",
        "CAO.TRAN.LUC 773423.pdf",
        "Hoang___Tan___Minh 773423.pdf"
    };

    vector<IRule*> rules;
    
    // Recreated all the rules from preset file "hrRules.txt"
    for (auto line : hrRules) { // line = "RemoveSpecialChars blacklist=-_+"
        int splitPosition = line.find_first_of(" ");
        string type = line.substr(0, splitPosition); // type = "RemoveSpecialChars"
        IParsable* parser = factory.create(type);

        // data = "blacklist=-_+"
        string data = line.substr(splitPosition + 1, line.length() - splitPosition - 1);
        IRule* rule = dynamic_cast<IRule*>(parser->parse(data));
        rules.push_back(rule);
    }

    // Apply all rename rules to each filename
    vector<string> renamedFiles;

    for (auto filename : filenames) {
        string newName = filename;

        for (auto rule : rules) {
            newName = rule->rename(newName);
        }

        renamedFiles.push_back(newName);
    }

    // Print out all renamed files
    for (int i = 0; i < filenames.size(); i++) {
        cout << filenames[i] << " => " << renamedFiles[i] << endl;
    }
}
```

## Sample output

```cpp
+++Cao---Minh----Long 773423.pdf  => CV 1122 Cao Minh Long devops.pdf
Tran    Huu  Nhan 773423.pdf      => CV 1122 Tran Huu Nhan devops.pdf
Do-Diem-Minh 773423.pdf           => CV 1122 Do Diem Minh devops.pdf
CAO.TRAN.LUC 773423.pdf           => CV 1122 CAO.TRAN.LUC devops.pdf
Hoang___Tan___Minh 773423.pdf     => CV 1122 Hoang Tan Minh devops.pdf
```