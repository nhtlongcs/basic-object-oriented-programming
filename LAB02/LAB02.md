# Lab 02 - Class & Object Basic

<aside>

🎯 Problems
1. Where is an object created and destroyed? What is heap & stack?
2. How to handle destruction automatically with a smart pointer?
3. How to create only one instance of a class using Singleton?
4. Where do we store the state of the program?
5. How to display objects using converters?

</aside>

# A. Exercises

## 1. Random fraction generator

### Initial information

- Name your project: **RandomFractionGenerator**

### Requirements

- [ ]  1. Print out the instructions for the program: **Random fraction generator**
- [ ]  2. Generate randomly an integer n in the range of [**5, 10**].
- [ ]  3. Generate randomly n fractions (each numerator and denominator of the fraction should be in the range of [**10, 100**]), and save them into a vector
- [ ]  4. Print out all the generated fractions in their normal form (no reduction)
- [ ]  5. Print out all the generated fractions in their lowest term
    - 5/1 ⇒ 5
    - 9/6 ⇒ 1 1/2
    - 4/6 ⇒ 2/3
- [ ]  6. Print out all the generated fractions in their decimal form (with the precision of 3 numbers after the decimal point)
- [ ]  7. Print out all the generated fractions in their percentage form (with the precision of 2 numbers after the decimal point)
    
### Example output
    

```
**Random fraction generator** 

Generating 6 fractions: 4/2, 14/4, 8/10, 7/2, 1/3, 2/4
Fractions in their lowest term: 2, 3 1/2, 4/5, 1/3, 1/2
Fractions in their decimal form: 2.000, 3.500, 0.800, 0.333, 0.500
Fractions in their percentage form: 200.00%, 3500.00%, 33.33%, 50.00% 
```

### Hints

1. To generate random fractions, you could create a business class for that named **RandomFractionGenerator**

```cpp
class RandomFractionGenerator {
public:
	Fraction next();
	Fraction next(int left, int right); // Numerator & denominator in [left, right] 
};
```

Basic usage

```cpp
RandomFractionGenerator rfg;
Fraction f = rfg.next(); 
Fraction f = rfg.next(10, 100);
```

2. To generate random integers, you could create a business class for that named **RandomIntegerGenerator**

```cpp
class RandomIntegerGenerator {
public:
	RandomIntegerGenerator(); // Do seeding here
public:
	int next(); // Integer in [0, 65535]
	int next(int ceiling); // Integer in [0, ceiling)
	int next(int left, int right); // Integer in [left, right]
};
```

Basic usage

```cpp
RandomIntegerGenerator rng;
int number = rng.next();
int maximum = rng.next(100); 
int inside = rng.next(10, 90);
```

Most of the time you will want this Random Integer Generator class to have only one instance throughout the operation of the program. In this case, turn it into Singleton

```cpp
class RandomIntegerGenerator {
public:
	// Only use inline with C++17
	**inline static RandomIntegerGenerator* _instance = NULL;**

private:
	// The constructor is hidden
	RandomIntegerGenerator() {
		srand(time(NULL));
	}

public:
	**static RandomIntegerGenerator* instance() {**
		if (_instance == NULL) {
			_instance = new RandomIntegerGenerator();
		}

		return _instance;
	}
public:
	int next();
	int next(int);
	int next(int, int);
};
```

Usage

```cpp
int number = RandomIntegerGenerator::instance()->next();
int maximum = RandomIntegerGenerator::instance()->next(100); 
int inside = RandomIntegerGenerator::instance()->next(10, 90);
```

Hint: The above implementation leaves a memory leak with the _instance pointer, this could be improved by using a smart pointer.

3. To turn a fraction into a string, you could write toString function (**do not abuse this function**)

```cpp
class Fraction {
public:
	string toString() {
		// Do not write
			// return _num + "/"+ _den
		// because the below codes will be better for debugging
		string result = _num + "/" + _den;
		return result;
	}
};
```

To concatenate a lot of substrings, it is better to use **stringstream**

```cpp
#include <sstream>
using namespace std;

class Fraction {
public:
	string toString() {
		stringstream builder; 
		builder << _num << "/" << _den;
	
		// Do not write
		// return builder.str() 
		// because the below codes will be better for debugging
		string result = builder.str();
		return result; 
	}
};
```

4. To find the greatest common divisor of two integers, you could write a static helper function inside an Integer class

 

```cpp
class Integer {
public:
	static int gcd(int a, int b);
};
```

Usage:

```cpp
int common = Integer::gcd(a, b);
```

5. To convert a fraction into its display form, rather than using the toString function you could write a converter instead:

```cpp
class FractionToDecimalConverter {
public:
	**string convert(Fraction f);** 
};
```

To turn this into a more general design, please consider this design for the converter class (inspired from C# WPF **IValueConverter**)

```cpp
**typedef void* Object;**

class FractionToDecimalConverter {
public:
	Object convert(Object o, Object arguments); 
	Object convertBack(Object o, Object arguments);
};

class FractionToLowestTermConverter {
public:
	Object convert(Object o, Object args); 
	Object convertBack(Object o, Object arguments);
};

class FractionToPercentageConverter {
public:
	Object convert(Object o, Object args); 
	Object convertBack(Object o, Object arguments);
};
```

**6. State of the screen**

The array of fractions is our main screen state. Normally we could have something like this

```cpp
void main() {
	vector<Fraction> fractions;

}
```

We could put it inside a global struct like this

```cpp
struct {
	vector<Fraction> fractions;
} state;

void main() {
	// access the fractions like this
	for(int i = 0; i < state.fractions.size(); ++i) {
	}
}
```

## 2. Working with fractions from the keyboard

### Initial information

- Name your project: **FractionsFromKeyboard**

### Requirements

- [ ]  1. Print out the instructions for the program: **Working with fractions from the keyboard**
- [ ]  2. Generate randomly an integer n in the range of [**5, 10**].
- [ ]  3. Enter n fractions from the keyboard, each numerator and denominator in the range of [**1, 100**]
- [ ]  4. Print out the sum of all the fractions in it loswest term.

### Example output (happy path)

```cpp
**Working with fractions from the keyboard**

Please enter 6 fractions.
Fraction [0]: 1/8
Fraction [1]: 2/8
Fraction [2]: 3/8
Fraction [3]: 4/8
Fraction [4]: 5/8
Fraction [5]: 6/8

The sum of all fractions is: 2 5/8
```

### Example output (unhappy path)

```cpp
**Working with fractions from the keyboard**

Please enter 6 fractions.
Fraction [0]: (press enter to get empty string)
**Error: Input cannot be empty.**

Fraction [0]: somestring
**Error: Invalid input format.** 

Fraction [0]: 12/tesing
**Error: Invalid input format.**

Fraction [0]: 12/0
**Error: Denominator cannot be zero.**

Fraction [0]: 200/300
**Error: The numerator and denominator should be in the range of [1, 100]**

Fraction [0]: 1/8
Fraction [1]: 2/8
Fraction [2]: 3/8
Fraction [3]: 4/8
Fraction [4]: 5/8
Fraction [5]: 6/8

The sum of all entered fractions is: 2 5/8
```
