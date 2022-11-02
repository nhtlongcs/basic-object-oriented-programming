# A. Exercises

### Initial information

- Name your project: **MyShop**

All the categories are stored in the file **"categories.txt"**, the content uses the following format:

```csharp
Category: ID=1, Name=Laptop
Category: ID=2, Name=Keyboard
Category: ID=3, Name=Mouse
```

All the products are stored in the file **"products.txt"**, the content uses the following format:

```csharp
Product: ID=15, Name=Dell XPS 9560, Price=40.000.000, CategoryID=1
Product: ID=16, Name=Macbook Pro 16" 2019, Price=70.000.000, CategoryID=1
Product: ID=17, Name=Surface Pro 8, Price=23.000.000, CategoryID=1
Product: ID=18, Name=Mitsumi M1, Price=300.000, CategoryID=2
Product: ID=19, Name=Logitech K380, Price=580.000, CategoryID=2
Product: ID=20, Name=Keychron K6, Price=1.200.000, CategoryID=2
Product: ID=21, Name=Apple Magic Mouse, Price=2.100.000, CategoryID=3
Product: ID=22, Name=Surface Mouse 2, Price=3.000.000, CategoryID=3
```

### Requirements

- [ ]  1. Print out the introduction to the program: **My Shop**
- [ ]  2. Create a menu that lets the user choose what to do with the program.

The menu could be in this format

```csharp
What do you want to do? 
1. Display all categories
2. Find products by name
3. Find products by price range

0. Quit

Please enter your choice: _
```

After finishing one function, please go back to this menu.

- [ ]  2.1. Display all categories

View all categories, then list all products of a chosen category

- [ ]  2.2. Find all products that contain a keyword entered from the keyboard, then display the result.

For example, if the keyword is "Mac"

```csharp
Searching for "Mac".
Found 1 result.
1. Category: Laptop, ID: 16, Name: Macbook Pro 16" 2019, Price: 70.000.000 d
```

You are only required to search inside the Name of the product. If the substring exists inside the target string regardless of lower case or upper case, return this result. 

- [ ]  2.3. Find all products whose price is in the range of [a, b] with a and b entered from the keyboard in natural format with thousand separators (For example 1.000.000). Display the result.

For example, if the range is [35.000.000, 70.000.000], the result would be

```csharp
Searching for products within the price range of [35.000.000, 70.000.000]. 
Found 2 results
1. Category: Laptop, ID: 15, Name: Dell XPS 9560, Price: 40.000.000 d
2. Category: Laptop, ID: 16, Name: Macbook Pro 16" 2019, Price: 70.000.000 d
```

# B. Submission instructions

If you write code using **onlinegdb.com**

- Make sure you have logged in
- Make sure you have saved your project and have given it a name
- Click the **Share** button to get the link to your project
- Put this link into a file in the format of {YourStudentID}.**txt** and submit back this text file.

If you write code using an **IDE** (Visual Studio, Visual Studio Code, or any IDE)

- Compress all your source code in the format of {YourStudentID}.**rar** or {YourStudentID}.**zip** and submit back this file.

# C. Frequently asked questions

0 questions here.