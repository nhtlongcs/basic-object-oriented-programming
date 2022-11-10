
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

```cpp
namespace Utils {
	class String {
	public:
		// Split a string into multiple sub strings
		static vector<string> split(string haystack, string needle);
	};

  class Integer {
	public:
    // Greatest common divisor
		static int gcd(int, int);
	};
}
```