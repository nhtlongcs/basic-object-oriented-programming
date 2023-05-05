## Usage
How to use the code

```bash
$ make main 
$ ./main
```

## 1. Working with shapes

- Name your project: **Shapes**
- Given the below main function, write all necessary files to make it run.

```cpp
int main() {
	vector<Rectangle*> rectangles = {
		new Rectangle(4, 7), // width + height
    new Rectangle(6, 8),
    new Rectangle(3, 2)
  };

  for(Rectangle* shape: rectangles){
    cout << shape->toString() << ": " 
         << "area=" << shape->area() << ", perimeter=" << shape->perimeter()
         << endl;
  }

	vector<Square*> squares= {
		new Square(7),
    new Square(6),
    new Square(9)
  };

  for(Square* shape: squares){
    cout << shape->toString() << ": " 
			   << "area=" << shape->area() << ", perimeter=" << shape->perimeter() 
				 << endl;
  }

   vector<Circle*> circles= {
		new Circle(4.3), // radius
    new Circle(5.5),
    new Circle(6.2)
  };

  for(Circle* shape: circles){
    cout << shape->toString() << ": " 
					<< "area=" << shape->area() << ", perimeter=" << shape->perimeter() 
					<< endl;
  }
}
```

## **Sample output**

```cpp
Rectangle w=4, h=7: area=28, perimeter=22
Rectangle w=6, h=8: area=48, perimeter=28
Rectangle w=3, h=2: area=6, perimeter=10
Square a=7: area=49, perimeter=28
Square a=6: area=36, perimeter=24
Square a=9: area=81, perimeter=36
Circle r=4.3, area=58.0586, perimeter=27.004
Circle r=5.5, area=94.985, perimeter=34.54
Circle r=6.2, area=128.4888, perimeter=38.936
```

## 2. Working with employees

- Name your project: **Employees**
- Given the below main function, write all necessary files to make it run.

```cpp
int main() {
	vector<DailyEmployee*> dailyEmployees= {
		new DailyEmployee(20, 1000000), // number of days, payment per day
    new DailyEmployee(22, 1100000),
    new DailyEmployee(18, 1500000)
  };

  // Daily employee's salary = number of days * payment per day
	for(DailyEmployee* employee: dailyEmployees) {
		cout << "Daily employee, salary:" << employee->salary() << endl;
  }

  vector<ProductEmployee*> productEmployees= {
		new ProductEmployee(790, 20000), // number of products, payment per product
    new ProductEmployee(810, 19000),
    new ProductEmployee(900, 18000)
  };

  // Product employee's salary = number of products * payment per product
	for(ProductEmployee* employee: productEmployees) {
		cout << "Product employee, salary:" << employee->salary() << endl;
  }

	vector<Manager*> managers= {
		new Manager(30, 5000000), // number of managed employees, fixed base payment per month
    new Manager(49, 6000000),
    new Manager(37, 7000000)
  };

  // Manager's salary = number of managed employees * 500.000 + fixed base payment per month
	for(Manager* employee: managers) {
		cout << "Manager, salary:" << employee->salary() << endl;
  }
}
```

## Sample output

```cpp
Daily employee, salary: 20.000.000 d
Daily employee, salary: 24.200.000 d
Daily employee, salary: 27.000.000 d
Product employee, salary: 15.800.000 d
Product employee, salary: 15.390.000 d
Product employee, salary: 16.200.000 d
Manager, salary: 20.000.000 d
Manager, salary: 30.500.000 d
Manager, salary: 25.500.000 d
```

## 3. Working with renaming rule

- Name your project: **RenamingRules**
- Given the below main function, write all necessary files to make it run.