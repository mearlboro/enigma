CXX      = g++
CXXFLAGS = -std=c++11 -g -Wall
CFLAGS   = -c -std=c++11

OBJS = machine.o rotor.o plugboard.o reflector.o util.o

enigma: Main.o $(OBJS)
	$(CXX) $(CXXFLAGS) $< -o $@

main.o: Main.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf enigma *.o
 
.PHONY: all clean
