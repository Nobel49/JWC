LIB = src/algo
OBJ = $(wildcard bin/*.o)


CFLAGS = -Wall 


all: main.o LZ77.o
	g++  $(OBJ) $(CFLAGS) -o bin/JWC.exe

test: bin/JWC.exe
	$^ test/input.txt test/output.txt

main.o: src/main.cpp
	g++ -c src/main.cpp -o bin/main.o


LZ77.o: $(LIB)/LZ77.cpp
	g++ -c $(LIB)/LZ77.cpp -o bin/LZ77.o

clean:
	cd bin
	del /S "*.o"
	cd ..