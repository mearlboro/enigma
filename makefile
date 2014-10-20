# edit this makefile so that running make compiles your enigma program

CFLAGS=-c -Wall -std=c++11

enigma: Main.o
	g++ -o enigma Main.o

Main.o: Main.cpp
	g++ $(CFLAGS) Main.cpp rotor.hpp reflector.hpp plugboard.hpp util.hpp

clean:
	rm -rf enigma *.o *.gch

.PHONY: clean
