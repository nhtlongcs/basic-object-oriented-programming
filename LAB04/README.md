## MyShop

To compile and run the program, type the following commands:

```bash
$ cd LAB04/MyShop
$ make 

Creating directories
make[1]: Entering directory '/home/nhtlong/oop/course/LAB04/MyShop'
Compiling: src/main.cpp -> build/main.o
g++  -std=c++11 -Wall -Wextra -g -I include/ -I /usr/local/include -MP -MMD -c src/main.cpp -o build/main.o
...
Linking: build/bin/main
g++ build/main.o -o build/bin/main 
Making symlink: main -> build/bin/main
make[1]: Leaving directory '/home/nhtlong/oop/course/LAB04/MyShop'

$ ./main

What do you want to do?
1. Display all categories
2. Find products by name
3. Find products by price range
0. Quit
Please enter your choice: 1
Categories: Laptop, Keyboard, Mouse, 

What do you want to do?
1. Display all categories
2. Find products by name
3. Find products by price range
0. Quit
Please enter your choice: 2
Please enter the name of the product you want to find: Mac
Found 1 products
[0] :ID: 16, Name: Macbook Pro 16\" 2019, Category: Laptop, Price: 70.000.000 d

What do you want to do?
1. Display all categories
2. Find products by name
3. Find products by price range
0. Quit
Please enter your choice: 3
Please enter the minimum price of the product you want to find: 3.000     
Please enter the maximum price of the product you want to find: 3.000.000
Searching for products within the price range of [3.000, 3.000.000]
Found 5 products
[0] :ID: 18, Name: Mitsumi M1, Category: Keyboard, Price: 300.000 d
[1] :ID: 19, Name: Logitech K380, Category: Keyboard, Price: 580.000 d
[2] :ID: 20, Name: Keychron K6, Category: Keyboard, Price: 1.200.000 d
[3] :ID: 21, Name: Apple Magic Mouse, Category: Mouse, Price: 2.100.000 d
[4] :ID: 22, Name: Surface Mouse 2, Category: Mouse, Price: 3.000.000 d
```
