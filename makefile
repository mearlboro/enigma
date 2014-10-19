# edit this makefile so that running make compiles your enigma program

CFLAGS=-c -Wall -std=c++11

enigma: Main.o
    g++ -o enigma Main.o

Main.o: Main.cpp
	g++ $(CFLAGS) Main.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
