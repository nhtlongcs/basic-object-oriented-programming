## DynamicArray 

To compile and run the program, type the following commands:

```bash
$ cd LAB05/DynamicArray
$ make 
Creating directories
make[1]: Entering directory '/home/nhtlong/oop/course/LAB05/DynamicArray'
Compiling: src/main.cpp -> build/main.o
g++  -std=c++11 -Wall -Wextra -g -I include/ -I /usr/local/include -MP -MMD -c src/main.cpp -o build/main.o
Linking: build/bin/main
g++ build/fraction.o build/main.o -o build/bin/main 
Making symlink: main -> build/bin/main
make[1]: Leaving directory '/home/nhtlong/oop/course/LAB05/DynamicArray'

$ ./main

Working with dynamic array of fractions from file
Reading input: data/data.txt
Expecting to have 5 fractions
Error: Invalid format
Found 4 fractions: 1 1/2, 2 , 1 1/6, 15/17
```

The program reads a list of fractions from a file and stores them in a dynamic array. The program then prints out the list of fractions. The file `data/data.txt` contains the following data:

```text
5
6/4
2/1
Corrupted data
14/12
15/17
```