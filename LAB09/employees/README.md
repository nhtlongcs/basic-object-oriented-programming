## Working with employees

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