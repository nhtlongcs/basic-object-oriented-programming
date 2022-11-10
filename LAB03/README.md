
## FractionDeserialization

To compile and run the program, type the following commands:

```bash
$ cd LAB03/FractionDeserialization
$ make


Creating directories
make[1]: Entering directory '/home/nhtlong/oop/course/LAB03/FractionDeserialization'
Compiling: src/fraction.cpp -> build/fraction.o
g++  -std=c++11 -Wall -Wextra -g -I include/ -I /usr/local/include -MP -MMD -c src/fraction.cpp -o build/fraction.o
Compiling: src/main.cpp -> build/main.o
g++  -std=c++11 -Wall -Wextra -g -I include/ -I /usr/local/include -MP -MMD -c src/main.cpp -o build/main.o
Linking: build/bin/main
g++ build/fraction.o build/main.o -o build/bin/main 
Making symlink: main -> build/bin/main
make[1]: Leaving directory '/home/nhtlong/oop/course/LAB03/FractionDeserialization'

$ ./main

Reading fractions from data.txt file...
Error: Invalid format
Error: Invalid format
Found 3 fractions: 3/7, 1 3/6, 3 1/2, 
The sum of all fractions is: 5 3/7
```

data.txt file contains the following data:

```bash
5
3/7
11/2invalid data
9/6
25/1invalid data
7/2
```

## PointSerialization

To compile and run the program, type the following commands:

```bash
$ cd LAB03/PointSerialization
$ make
Creating directories
make[1]: Entering directory '/home/nhtlong/oop/course/LAB03/PointSerialization'
Compiling: src/main.cpp -> build/main.o
g++  -std=c++11 -Wall -Wextra -g -I include/ -I /usr/local/include -MP -MMD -c src/main.cpp -o build/main.o
...
Linking: build/bin/main
g++ build/main.o build/point.o -o build/bin/main 
Making symlink: main -> build/bin/main
make[1]: Leaving directory '/home/nhtlong/oop/course/LAB03/PointSerialization'

$ ./main
```

The program will create a file named `output.txt` containing the following data:

```bash
1/2
3/4
```