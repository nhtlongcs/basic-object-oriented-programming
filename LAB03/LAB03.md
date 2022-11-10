# Lab 03 - Serialization & Deserialization

<aside>

🎯 **Objectives**
1. Reading data from the text file
2. Writing data to the text file

</aside>

## 1. Fraction Deserialization

### Initial information

- Name your project: **FractionDeserialization**

### Requirements

- [ ]  1. Print out the introduction for the program: **Fraction deserialization**
- [ ]  2. Read all the fractions stored inside the file data.txt. You can use your own format, or you can use the suggested below file

**The first line contains the number of fractions inside the file**

```cpp
5
3/7
11/2
9/6
25/1
7/2
```

- [ ]  3. Print out all the fractions that you have read from the file
- [ ]  4. Print out the sum of all fractions in its lowest term

### Example output (happy path)

```cpp
Fraction deserialization

Reading fractions from data.txt file...
Found 5 fractions: 3/7, 5 1/2, 1 1/2, 25, 3 1/2
The sum of all fractions is: 35 13/14
```

### Example output 1 (unhappy path)

Example input

This file contains some invalid lines, we can skip it.

```cpp
5
3/7
11/2invalid data
9/6
25/1invalid data
7/2
```

Example output

```cpp
Fraction deserialization

Reading fractions from data.txt file...
Found 3 fractions: 3/7, 1 1/2, 3 1/2
The sum of all fractions is: 5 3/7
```

### Example output 2 (unhappy path)

```cpp
Fraction serialization & deserialization

Reading fractions from data.txt file...
File not found. 
Exiting the program.
```

## Point Serialization

### Initial Information

- Name your project: **PointSerialization**

### Requirements

- [ ]  1. Print out the introduction for the program: **Point serialization**
- [ ]  2. Generate a random integer n in the range of [5, 10]
- [ ]  3. Generate randomly n 2D points with x and y coordinates in the range of [1, 100]
- [ ]  4. Print out all generated 2D points to the file **points.txt**. You could use your own format or you could use the suggested file format:

The first line contains the number of generated points