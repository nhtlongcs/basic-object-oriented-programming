## IntegersFromKeyboard

To compile and run the program, type the following commands:

```bash
$ cd LAB01/IntegersFromKeyboard
$ make

Creating directories
make[1]: Entering directory '/home/nhtlong/oop/course/LAB01/IntegersFromKeyboard'
Compiling: src/IntegersFromKeyboard.cpp -> build/IntegersFromKeyboard.o
g++  -std=c++11 -Wall -Wextra -g -I include/ -I /usr/local/include -MP -MMD -c src/IntegersFromKeyboard.cpp -o build/IntegersFromKeyboard.o
...
Linking: build/bin/main
g++ build/IntegersFromKeyboard.o build/main.o -o build/bin/main 
Making symlink: main -> build/bin/main
make[1]: Leaving directory '/home/nhtlong/oop/course/LAB01/IntegersFromKeyboard'

$ ./main

Working with integer arrays from the keyboard
Please enter an integer in the range of [5, 10]: 5
Please enter 5 integer(s), each in the range of [1, 100]: 
The [0] integer: 12

The [1] integer: 1000
Error: Out of range
The [1] integer: 0   
Error: Out of range
The [1] integer: 12

The [2] integer: 3

The [3] integer: 1mn1
Error: Invalid format
The [3] integer: 5

The [4] integer: 10

You have entered 5 integer(s):
12 12 3 5 10 
Found 2 odd numbers: 
3 5 
Found 3 even numbers: 
12 12 10 
Found 2 palindrom numbers: 
3 5 
Found 2 prime numbers: 
3 5 
```

## RandomlyGeneratedIntegers 

To compile and run the program, type the following commands:


```bash
$ cd LAB01/RandomlyGeneratedIntegers
$ make

Creating directories
make[1]: Entering directory '/home/nhtlong/oop/course/LAB01/RandomlyGeneratedIntegers'
Compiling: src/RandomlyGeneratedIntegers.cpp -> build/RandomlyGeneratedIntegers.o
g++  -std=c++11 -Wall -Wextra -g -I include/ -I /usr/local/include -MP -MMD -c src/RandomlyGeneratedIntegers.cpp -o build/RandomlyGeneratedIntegers.o
...
Linking: build/bin/main
g++ build/main.o build/RandomlyGeneratedIntegers.o -o build/bin/main 
Making symlink: main -> build/bin/main
make[1]: Leaving directory '/home/nhtlong/oop/course/LAB01/RandomlyGeneratedIntegers'

$ ./main 

Working with randomly generated integers 
Generating 8 integer(s):
68 20 24 98 30 33 81 88 
Found 2 odd numbers: 
33 81 
Found 6 even numbers: 
68 20 24 98 30 88 
Found 2 palindrom numbers: 
33 88 
Found 1 square numbers: 
81 
```