@echo off


set CXXFLAGS= -Wall -O3 -g -Wextra -std=c++14 -Wno-unused-variable


g++ src/main.cpp -c %CXXFLAGS% -o bin/main.o
g++ src/misc.cpp -c %CXXFLAGS% -o bin/misc.o
g++ src/algo/LZ77.cpp -c %CXXFLAGS% -o bin/LZ77.o

g++ bin/*.o -o bin/jwc