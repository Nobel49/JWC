LIB = ./src/algo
OBJ = $(wildcard bin/*.o)
CXX = c++14


CFLAGS = -Wall -O3 -g -Wextra -std=$(CXX) -Wno-unused-variable

all: misc.o main.o LZ77.o
	g++  $(OBJ) $(CFLAGS) -o bin/jwc.exe

misc.o: src/misc.cpp
	g++ -c $^ -o bin/$@ $(CFLAGS)

main.o: src/main.cpp
	g++ -c $^ -o bin/$@ $(CFLAGS)


LZ77.o: $(LIB)/LZ77.cpp
	g++ -c $^ -o bin/$@ $(CFLAGS)


