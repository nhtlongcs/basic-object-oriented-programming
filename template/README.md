Generic makefile example for a C++ project
If you need a small makefile introduction/reference you can take a look at my notes https://www.mauriciopoppe.com/notes/os/bin/make/

$ sh new.sh to create project structure following the template

. project
├── Makefile
├── build
├── include
│  └── project
│    └── Vector.hpp
└── src
    ├── Vector.cpp
    └── main.cpp
$ make
Creating directories
Compiling: src/Vector.cpp -> build/Vector.o
c++  -std=c++11 -Wall -Wextra -g -I include/ -I /usr/local/include -MP -MMD -c src/Vector.cpp -o build/Vector.o
Compiling: src/main.cpp -> build/main.o
c++  -std=c++11 -Wall -Wextra -g -I include/ -I /usr/local/include -MP -MMD -c src/main.cpp -o build/main.o
Linking: build/bin/runner
c++ build/Vector.o build/main.o -o build/bin/runner
Making symlink: runner -> build/bin/runner

$ ./runner
(3,3)

$ make clean
Deleting runner symlink
Deleting directories
Generic makefile stolen from https://github.com/mbcrawfo/GenericMakefile