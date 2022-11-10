## FractionsFromKeyboard

To compile and run the program, type the following commands:

```bash
$ cd LAB02/FractionsFromKeyboard
$ make

Creating directories
make[1]: Entering directory '/home/nhtlong/oop/course/LAB02/FractionsFromKeyboard'
Compiling: src/fraction.cpp -> build/fraction.o
g++  -std=c++11 -Wall -Wextra -g -I include/ -I /usr/local/include -MP -MMD -c src/fraction.cpp -o build/fraction.o
...
Linking: build/bin/main
g++ build/fraction.o build/main.o -o build/bin/main 
Making symlink: main -> build/bin/main
make[1]: Leaving directory '/home/nhtlong/oop/course/LAB02/FractionsFromKeyboard'

$ ./main

Working with fractions from the keyboard
Please enter 5 fractions.
Fraction [0]: 
Error: Empty input
Fraction [0]: 1/2

Fraction [1]: 10/0
Error: Denominator cannot be zero
Fraction [1]: 100/10

Fraction [2]: 1/2

Fraction [3]: 1/1

Fraction [4]: 1/1

The sum of all fractions is: 13 
```

## RandomFractionGenerator

To compile and run the program, type the following commands:

```bash
$ cd LAB02/RandomFractionGenerator
$ make

Creating directories
make[1]: Entering directory '/home/nhtlong/oop/course/LAB02/RandomFractionGenerator'
Compiling: src/fraction.cpp -> build/fraction.o
g++  -std=c++11 -Wall -Wextra -g -I include/ -I /usr/local/include -MP -MMD -c src/fraction.cpp -o build/fraction.o
...
Linking: build/bin/main
g++ build/fraction.o build/main.o -o build/bin/main 
Making symlink: main -> build/bin/main
make[1]: Leaving directory '/home/nhtlong/oop/course/LAB02/RandomFractionGenerator'

$ ./main

Generating 6 fractions: 5 2/12, 2 2/6, 8 2/11, 14 2/7, 4 2/8, 13/14, 
Fractions in their lowest term: 5 1/6, 2 1/3, 8 2/11, 14 2/7, 4 1/4, 13/14, 
Fractions in their decimal form: 5.16667, 2.33333, 8.18182, 14.2857, 4.25, 0.928571, 
Fractions in their percentage form: 516.666667%, 233.333333%, 818.181818%, 1428.571429%, 425.000000%, 92.857143%, 
```