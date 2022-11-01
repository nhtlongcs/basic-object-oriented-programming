
### Hints

1. To get a fraction from the keyboard you can create a function named parse().

You could throw an exception inside this function or you can use the suggested version below using error codes and messages:

```cpp
class Fraction {
public:
	**static tuple<bool, Fraction, int, string> parse(string buffer, int left, int right) {**
		bool success = true;
		Fraction data;
		int errorCode = 0;
		string message = "";
	
		auto result = make_tuple(success, data, errorCode, message);
		return result;
	}
};
```

 You could define an enum for the error codes

```cpp
class Fraction {
public:
	enum ParseErrorCode {
		EmptyInput,
		InvalidInputFormat,
		ZeroDenominator,
		ValueNotInDomain
	};
}
```

You can access the error code outside like this

```cpp
Fraction::ParseErrorCode::EmptyInput
Fraction::ParseErrorCode::InvalidInputFormat
```

2. The regular expression for fraction is “\d+\/\d+”

In C++, it should be "\\d+\\/\\d+”
