# edit this makefile so that running make compiles your enigma program

CFLAGS=-c -std=c++11

enigma: Main.o
	g++ -o enigma Main.o

Main.o: Main.cpp machine.hpp reflector.hpp rotor.hpp plugboard.hpp encryptor.hpp 
	g++ $(CFLAGS) Main.cpp 

# machine.o: machine.cpp reflector.o rotor.o plugboard.o
# 	g++ $(CFLAGS) machine.cpp 
# 
clean:
	rm -rf enigma *.o *.gch
# 
# reflector.o : reflector.cpp reflector.hpp encryptor.hpp
# 	g++ $(CFLAGS) reflector.cpp 
# 
# rotor.o: rotor.cpp rotor.hpp encryptor.hpp util.hpp
# 	g++ $(CFLAGS) rotor.cpp
# 
# plugboard.o: plugboard.cpp plugboard.hpp encryptor.hpp
# 	g++ $(CFLAGS) plugboard.cpp
# 
.PHONY: clean
