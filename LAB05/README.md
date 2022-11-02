# Lab 05 - Dynamic Array

# Requirements

- [ ]  Practice using class template, create a dynamic array class.
- [ ]  Read all fractions stored from fractions.txt files into a dynamic array of Fraction
- [ ]  Print out all parsed fractions in its lowest term

## Sample fractions.txt file content

```cpp
5
6/4
2/1
Corrupted data
14/12
15/17
```

## Example output

```cpp
Working with dynamic array of fractions from file

Reading input: fractions.txt
Expecting to have 5 fractions

Found 4 fractions: 1 1/2, 2, 1 1/6, 15/17
```

## Hints

```cpp
template <class T>
class DynamicArray {
private:
		T* _data;
    int _maxSize;
    int _currentSize;
public:
		DynamicArray();
	  int size();
    void push_back(T value);
    T operator[](int i);
};
```

```cpp
class Fraction {
private:
	int _num;
  int _den;
public:
	Fraction();
	Fraction(int, int);
  static Fraction parse(string line);
};

class FractionToLowestTermConverter {
public:
		string converter(const Fraction& f) {
					stringstream builder;
					// TODO: Find the lowest term of the fraction here

					string result = builder.str();
          return result;
		}
};
```

You will need some helper classes: