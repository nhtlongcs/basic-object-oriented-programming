## Check if a file exists

```cpp
inline bool exists(const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}
```

Further reading to find out more methods of checking if a file exists and what is the fastest method

[Fastest way to check if a file exists using standard C++/C++11,14,17/C?](https://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exists-using-standard-c-c11-14-17-c)

## Read all lines of a text file

```cpp
#include <fstream>

ifstream reader;
reader.open("test.txt", ios::in);

while (!reader.eof()) {
    string buffer;
    getline(reader, buffer);
    cout << buffer << endl;
}

reader.close();
```

## Write all objects to a text file

```cpp
inline bool exists(const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}
```