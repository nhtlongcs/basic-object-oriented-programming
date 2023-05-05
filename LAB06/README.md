# LAB 06 - Employee salary
# Requirements

- [x]  Read all employee’s information from **salary112022.txt** file
- [x]  Print out the list of all employees back to the screen, sorted by salary in descending order

The formula for computing salary for an employee is 

```
WorkDay * Products * 1.000
```
### Sample **salary112022.txt**

```csharp
5
Employee ID=1, Name=Nguyen Huu Chanh, WorkDay=15, Products=200
Employee ID=3, Name=Tran Thai Tuan, WorkDay=13, Products=700
Employee ID=21, Name=Nguyen Minh Hanh, WorkDay=12, Products=770
Employee ID=33, Name=Tran Khanh Linh, WorkDay=18, Products=900
Employee ID=36, Name=Dang Dinh Long, WorkDay=14, Products=650
```

### Sample output

```cpp
Employee ID=33, Name=Tran Khanh Linh, WorkDay=18, Products=900, Salary=16.200.000 đ
Employee ID=21, Name=Nguyen Minh Hanh, WorkDay=12, Products=770, Salary=9.240.000 đ
Employee ID=36, Name=Dang Dinh Long, WorkDay=14, Products=650, Salary=9.100.000 đ
Employee ID=3, Name=Tran Thai Tuan, WorkDay=13, Products=700, Salary=9.100.000 đ
Employee ID=1, Name=Nguyen Huu Chanh, WorkDay=15, Products=200, Salary=3.000.000 đ
```


# Submission 

Generic makefile example for a C++ project
If the folder only contains a single source file (or maybe one include file), you can compile it with the following command:
```bash
$ make
```

```bash
. project
├── Makefile
├── build
├── include
│  └── project
│    └── Vector.hpp
└── src
    ├── Vector.cpp
    └── main.cpp
```

Expected results of input file `data/salary112022.txt`:

```C#
5
Employee ID=1, Name=Nguyen Huu Chanh, WorkDay=15, Products=200
Employee ID=3, Name=Tran Thai Tuan, WorkDay=13, Products=700
Employee ID=21, Name=Nguyen Minh Hanh, WorkDay=12, Products=770
Employee ID=33, Name=Tran Khanh Linh, WorkDay=18, Products=900
Employee ID=36, Name=Dang Dinh Long, WorkDay=14, Products=650
```

Console log
```bash
$ make
Creating directories
make[1]: Entering directory '/home/nhtlong/oop/course/LAB06'
Compiling: src/employee.cpp -> build/employee.o
g++  -std=c++11 -Wall -Wextra -g -I include/ -I /usr/local/include -MP -MMD -c src/employee.cpp -o build/employee.o
Compiling: src/main.cpp -> build/main.o
g++  -std=c++11 -Wall -Wextra -g -I include/ -I /usr/local/include -MP -MMD -c src/main.cpp -o build/main.o
...
Linking: build/bin/main
g++ build/employee.o build/main.o build/manager.o build/salary.o -o build/bin/main 
Making symlink: main -> build/bin/main
make[1]: Leaving directory '/home/nhtlong/oop/course/LAB06'

$ ./main 
[INFO] Employee: ID=33, Name=Tran Khanh Linh, WorkDays=18, Products=900, Salary=16.200.000 đ
[INFO] Employee: ID=21, Name=Nguyen Minh Hanh, WorkDays=12, Products=770, Salary=9.240.000 đ
[INFO] Employee: ID=3, Name=Tran Thai Tuan, WorkDays=13, Products=700, Salary=9.100.000 đ
[INFO] Employee: ID=36, Name=Dang Dinh Long, WorkDays=14, Products=650, Salary=9.100.000 đ
[INFO] Employee: ID=1, Name=Nguyen Huu Chanh, WorkDays=15, Products=200, Salary=3.000.000 đ

$ make clean
Deleting main symlink
Deleting directories
```


Console debug log (uncomment `logger->debug()` in `src/main.cpp`)

```bash
$ make
Creating directories
make[1]: Entering directory '/home/nhtlong/oop/course/LAB06'
Compiling: src/employee.cpp -> build/employee.o
g++  -std=c++11 -Wall -Wextra -g -I include/ -I /usr/local/include -MP -MMD -c src/employee.cpp -o build/employee.o
Compiling: src/main.cpp -> build/main.o
g++  -std=c++11 -Wall -Wextra -g -I include/ -I /usr/local/include -MP -MMD -c src/main.cpp -o build/main.o
...
Linking: build/bin/main
g++ build/employee.o build/main.o build/manager.o build/salary.o -o build/bin/main 
Making symlink: main -> build/bin/main
make[1]: Leaving directory '/home/nhtlong/oop/course/LAB06'

$ ./main 

Debug mode is on
[DEBUG] Number of employees: 5
[DEBUG] Line: Employee ID=1, Name=Nguyen Huu Chanh, WorkDay=15, Products=200
[DEBUG] Line: Employee ID=3, Name=Tran Thai Tuan, WorkDay=13, Products=700
[DEBUG] Line: Employee ID=21, Name=Nguyen Minh Hanh, WorkDay=12, Products=770
[DEBUG] Line: Employee ID=33, Name=Tran Khanh Linh, WorkDay=18, Products=900
[DEBUG] Line: Employee ID=36, Name=Dang Dinh Long, WorkDay=14, Products=650
[DEBUG] Printing raw employees
[DEBUG] raw salary: 3000000
[DEBUG] Employee: ID=1, Name=Nguyen Huu Chanh, WorkDays=15, Products=200, Salary=3.000.000 đ
[DEBUG] raw salary: 9100000
[DEBUG] Employee: ID=3, Name=Tran Thai Tuan, WorkDays=13, Products=700, Salary=9.100.000 đ
[DEBUG] raw salary: 9240000
[DEBUG] Employee: ID=21, Name=Nguyen Minh Hanh, WorkDays=12, Products=770, Salary=9.240.000 đ
[DEBUG] raw salary: 16200000
[DEBUG] Employee: ID=33, Name=Tran Khanh Linh, WorkDays=18, Products=900, Salary=16.200.000 đ
[DEBUG] raw salary: 9100000
[DEBUG] Employee: ID=36, Name=Dang Dinh Long, WorkDays=14, Products=650, Salary=9.100.000 đ
[DEBUG] Printing employees
[DEBUG] raw salary: 16200000
[INFO] Employee: ID=33, Name=Tran Khanh Linh, WorkDays=18, Products=900, Salary=16.200.000 đ
[DEBUG] raw salary: 9240000
[INFO] Employee: ID=21, Name=Nguyen Minh Hanh, WorkDays=12, Products=770, Salary=9.240.000 đ
[DEBUG] raw salary: 9100000
[INFO] Employee: ID=3, Name=Tran Thai Tuan, WorkDays=13, Products=700, Salary=9.100.000 đ
[DEBUG] raw salary: 9100000
[INFO] Employee: ID=36, Name=Dang Dinh Long, WorkDays=14, Products=650, Salary=9.100.000 đ
[DEBUG] raw salary: 3000000
[INFO] Employee: ID=1, Name=Nguyen Huu Chanh, WorkDays=15, Products=200, Salary=3.000.000 đ

$ make clean
Deleting main symlink
Deleting directories
```