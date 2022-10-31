## 1. The death loop

```cpp
bool shouldRepeat = false;

do {

	shouldRepeat = true; // (check condition here);
} while (shouldRepeat);
```

## 2. Convert a string into an integer

```cpp
#include <string>
using namespace std;

string buffer = "12";
**int number = stoi(buffer);**
cout << number * 2;
```

## 3. Getting a number from the keyboard

```cpp
#include <string>
using namespace std;

string buffer;
**getline(cin, buffer);
int number = stoi(buffer);**
```

We should do this in order to avoid the redundant enter character on the buffer of the input stream. This problem only arises when inputting a lot of different types of values.

You should avoid the below methods of getting data

```cpp
// There is hidden problem when inputing from the keyboard
// The enter key is still on the buffer, which will cause unwanted behavior
int number;
cin >> number;

string name;
getline(cin, name);

double range;
cin >> range;

string city;
getline(cin, city);
```

Instead, always get from the console input stream a string, then convert it to the corresponding desired type.

## 4. Working with dynamic array (vector)

To add numbers into a vector:

```cpp
#include <vector>
using namespace std;

vector<int> numbers = {
	1, 2, 3
};

numbers.push_back(4);
numbers.push_back(5);
```

To loop through a vector:

```cpp
for(int i = 0; i < numbers.size(); ++i) {
	int value = numbers[i];
}
```

Changing an item's value using index

```cpp
numbers[2] = 111;
numbers[3] = 999;
```

## 5. Generate random integers

First, give the generator a seed:

```cpp
srand(time(NULL)); // Should only be called once
```

Call the rand() function multiple times for multiple random integers

```cpp
srand(time(NULL)); // Should only be called once

for(int i = 0; i < 10; ++i) {
	int number = rand();
}
```

**What if we put the seeding function srand() inside a loop?**

```cpp
for(int i = 0; i < 10; ++i) {
	srand(time(NULL)); 
	cout << rand() << " ";
}
```

You should see an unexpected result like this (All generated numbers are **the same**, WHY?)

```cpp
9 9 9 9 9 9 9 9 9 9
```

## 6. Function pointer

Try writing only one function reduce to create sub array from the original array and using a function pointer to assign the needed filtering condition.

First we define the function pointer type

```cpp
typedef bool (*Predicate)(int number);
```

Then write the universal reduce function for a vector

```cpp
vector<int> reduce(vector<int> a, Predicate satisfy) {
	vector<int> result;

	for(int i = 0; i < a.size(); ++i) {
		if (satisfy(a[i]) {
			result.push_back(a[i]);	
		}
	}	

	return result;
}
```

Finally, we use them in the code

```cpp
auto odds = reduce(a, isOdd);
auto evens = reduce(a, isEven);
auto palindromes = reduce(a, isPalindromic);
auto squares = reduce(a, isPrime);
```

## 7. Tuple

To return more than one value in a function, try using tuple

```cpp
#include <tuple>
using namespace std;

tuple<int, string> result = make_tuple(1, "info");
cout << get<0>(result);
cout << get<1>(result);

int number;
string message;
tie(number, message) = make_tuple(10, "Error");
```

A normal function should return 4 information:

- Success: bool. Indicate the success of this operation
- Data: int (or any type). The result data type
- ErrorCode: int. The error code for the failed operation
- Message: string. A detailed description of the error

We may need more information inside

- ErrorCodeEnum: enum. List all the possible error codes

Definition

```cpp
#include <tuple>
#include <string>
using namespace std;

enum IntegerParseErrorCode {
  EmptyInput,
  InvalidFormat,
  ValueNotInDomain
};

tuple<bool, int, int, string> parse(string buffer, int left, int right) {
	bool success = true;
	int data = 0;
	int errorCode = 0;
	string message = 0;
  
  if (buffer.length() == 0) {
      success = false;
      errorCode = IntegerParseErrorCode::EmptyInput;
      message = "Input cannot be empty";
  }
	

	// tuple<bool, int, int, string> result = make_tuple(success, data, errorCode, message);
	auto result = make_tuple(success, data, errorCode, message);
	return result;	
}
```

Usage:

```cpp
#include <tuple>
using namespace std;

bool success = true;
int data = 0;
int errorCode = 0;
string message = "";

string buffer;
getline(cin, buffer);

tie(success, data, errorCode, message) = parse(buffer, left, right);

if (success) {
	// we get the data we want
} else {
	// handle failed cases
}
```

## 8. Pluralization

Add a helper function for pluralization:

```cpp
#include <sstream>
#include <string>
using namespace std;

string pluralize(int count, string singular, string plural) {
	stringstream builder;
	buidler << count << " ";

	if (count <= 1) {
		builder << singular;
	} else {
		builder << plural;
	}

	string result = builder.str();
	return result;
}
```

Usage:

```cpp
int count = 3;
pluralize(count, "message", "messages"); // 3 messages

int zero = 0;
pluralize(zero, "message", "messages"); // 0 message
```

## 9. Regular expression

We can use regular expression to describe our desired string pattern

```cpp
#include <regex>
using namespace std;

string pattern = "\\d+"; // \d: digits only 0-9, +: one or more
bool matched = regex_match(buffer, regex(pattern));
```

You can use an external tool to help leaning about regular expression

[RegExr: Learn, Build, & Test RegEx](https://regexr.com/)
