# Lab 10 - Final project - Display table of students

# Requirements

- [x]  Name your project - **StudentTable**
- [x]  Write all necessary codes to make this main function works

```cpp
int main()
{
    vector<Object*> data = {
        new Student("Tran Huu Long", "0909888712", "227 Nguyen Van Cu P4 Q5"),
        new Student("Cao Duc Tuan", "0773256712", "177 Nguyen Dinh Chieu Q3"),
        new Student("Le Mai Loan", "0869327617", "17 Tran Phu Q2"),
        new Student("Dinh Thi Ly", "0999876432", "35 Vo Thi Sau Q1"),
        new Student("Nguyen Duc Vinh", "0999882725", "15 Vo Van Tan P11 Binh Thanh"),
    };
    vector<string> headers = {
        "Ho va ten", "SDT", "Dia chi"
    };
    vector<int> widths = {
        15, 11, 28
    };
    IValueConverter* converter = new StudentToRowConverter(widths);
    
    Table table(headers, widths, data, converter);
    table.display();
}
```

## Sample output

```cpp
      Ho va ten|        SDT|                     Dia chi|
---------------------------------------------------------
  Tran Huu Long| 0909888712|     227 Nguyen Van Cu P4 Q5|
   Cao Duc Tuan| 0773256712|    177 Nguyen Dinh Chieu Q3|
    Le Mai Loan| 0869327617|              17 Tran Phu Q2|
    Dinh Thi Ly| 0999876432|            35 Vo Thi Sau Q1|
Nguyen Duc Vinh| 0999882725|15 Vo Van Tan P11 Binh Thanh|
---------------------------------------------------------
```


# Compile and run

Folder structure

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

Use `make` command to compile code. Use `make clean` to delete all generated files. See example below.

```bash
$ make
Creating directories
make[1]: Entering directory '/home/nhtlong/oop/course/LAB10/StudentTable'
Making symlink: main -> build/bin/main
make[1]: Leaving directory '/home/nhtlong/oop/course/LAB10/StudentTable'

$ ./main
+---------------+-----------+----------------------------+
|      Ho va ten|        SDT|                     Dia chi|
+---------------+-----------+----------------------------+
|  Tran Huu Long| 0909888712|     227 Nguyen Van Cu P4 Q5|
|   Cao Duc Tuan| 0773256712|    177 Nguyen Dinh Chieu Q3|
|    Le Mai Loan| 0869327617|              17 Tran Phu Q2|
|    Dinh Thi Ly| 0999876432|            35 Vo Thi Sau Q1|
|Nguyen Duc Vinh| 0999882725|15 Vo Van Tan P11 Binh Thanh|
+---------------+-----------+----------------------------+

$ make clean
Deleting main symlink
Deleting directories
```

