Generic makefile example for a C++ project
If the folder only contains a single source file (or maybe one include file), you can compile it with the following command:
```bash
$ make
```
`$ sh new.sh` to create project structure following the template

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
```bash
$ make
Creating directories
Compiling: src/Vector.cpp -> build/Vector.o
c++  -std=c++11 -Wall -Wextra -g -I include/ -I /usr/local/include -MP -MMD -c src/Vector.cpp -o build/Vector.o
Compiling: src/main.cpp -> build/main.o
c++  -std=c++11 -Wall -Wextra -g -I include/ -I /usr/local/include -MP -MMD -c src/main.cpp -o build/main.o
Linking: build/bin/main
c++ build/Vector.o build/main.o -o build/bin/main
Making symlink: main -> build/bin/main

$ ./main
(3,3)

$ make clean
Deleting main symlink
Deleting directories
```
Generic makefile stolen from https://github.com/mbcrawfo/GenericMakefile