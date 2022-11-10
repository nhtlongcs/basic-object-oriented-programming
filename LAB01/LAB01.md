# Lab 01 - Working with integer arrays 

<aside>

🎯 Problems
1. Looping until getting a valid number from the keyboard
2. Returning multiple values from a function
3. Generate randomly an integer
3. Save all numbers into a dynamic array (vector)
4. Using function pointer for reducing an array

</aside>

# Exercises

## 1. Working with integer arrays from the keyboard

### Initial information

- Name your project: **IntegersFromKeyboard**

### Requirements

- [ ]  1. Print out the instructions for the program: **Working with integer arrays from the keyboard**
- [ ]  2. Enter an integer n in the range of [**5, 10**].
- [ ]  3. Enter n integers, each integer in the range of [**1, 100**] and save them into a vector
- [ ]  4. Find all odd numbers, all even numbers, all palindromic numbers, all prime numbers

### Example output (happy path)

```
Working with integer arrays from the keyboard.

Please enter an integer in the range of [5, 10]: 6

Please enter 6 integer(s), each in the range of [1, 100]:
The [0] integer: 12
The [1] integer: 4
The [2] integer: 77
****The [3] integer: 26
The [4] integer: 33
The [5] integer: 99

You have entered 6 integer(s): 12, 4, 77, 26, 33, 99
Found 3 odd number(s): 77, 33, 99
Found 3 even number(s): 12, 4, 26
Found 4 palindromic number(s): 4, 77, 33, 99
Found 1 prime number(s): 4
```

### Example output (unhappy path)

```
Working with integer arrays from the keyboard.

Please enter an integer in the range of [5, 10]: (Press enter)
**Error: Input string cannot be empty.**

Please enter an integer in the range of [5, 10]: allstring
**Error: Invalid input format.**

Please enter an integer in the range of [5, 10]: 20
**Error: The integer must be in the range of [5, 10]**

Please enter an integer in the range of [5, 10]: 6 
*.... (continue as the happy path above)*
```

### Improvement - Enhanced output

Rather than

```
...
You have entered 6 integer(s): 12, 4, 77, 26, 33, 99
Found 3 odd number(s): 77, 33, 99
Found 3 even number(s): 12, 4, 26
Found 4 palindromic number(s): 4, 77, 33, 99
Found 1 prime number(s): 4
```

Can you generate this output instead?

```
...
You have entered **6 integers**: 12, 4, 77, 26, 33, 99
Found **3 odd numbers**: 77, 33, 99
Found **3 even numbers**: 12, 4, 26
Found **4 palindromic numbers**: 4, 77, 33, 99
Found **1 prime number**: 4
```

Hint: add a helper function to decide 

## 2. Generating integers randomly

### Initial information

- Name your project: **RandomlyGeneratedIntegers**

### Requirements

- [ ]  1. Print out the instructions for the program: **Working with randomly generated integers**
- [ ]  2. Generate randomly an integer n in the range of [**5, 10**].
- [ ]  3. Generate randomly n integers, each integer in the range of [**10, 100**], and save them into a vector
- [ ]  4. Find all odd numbers, all even numbers, all palindromic numbers, all square numbers

### Example output (happy path)

```
**Working with randomly generated integers** 

Generating 6 integers: 12, 4, 77, 26, 33, 99
Found **3 odd numbers**: 77, 33, 99
Found **3 even numbers**: 12, 4, 26
Found **4 palindromic numbers**: 4, 77, 33, 99
Found **1 prime number**: 4
```
