# edit this makefile so that running make compiles your enigma program

CFLAGS=-c -Wall -std=c++11

enigma: Main.o
	g++ -o enigma Main.o

Main.o: Main.cpp
	g++ $(CFLAGS) Main.cpp Rotor.o Reflector.o Plugboard.o

Rotor.o: rotor.cpp
	g++ $(CFLAGS) encryptor.hpp rotor.hpp rotor.cpp

Reflector.o: reflector.cpp
	g++ $(CFLAGS) encryptor.hpp reflector.hpp reflector.cpp

Plugboard.o: plugboard.cpp
	g++ $(CGLAGS) encryptor.hpp plugboard.hpp plugboard.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
