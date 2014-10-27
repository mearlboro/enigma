CXX      = g++
CXXFLAGS = -std=c++11 -g -Wall
CFLAGS   = -c -std=c++11

OBJS = rotor.o plugboard.o reflector.o util.o

enigma: Main.o machine.o $(OBJS)
	$(CXX) $(CXXFLAGS) $< -o $@

Main.o: Main.cpp machine.o $(OBJS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

machine.o: machine.cpp encryptor.hpp $(OBJS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# rotor.o: rotor.cpp encryptor.hpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@
# 
# plugboard.o: plugboard.cpp encryptor.hpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@
# 
# reflector.o: reflector.cpp encryptor.hpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@
# 
# util.o: util.cpp encryptor.hpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@
#  
clean:
	rm -rf enigma *.o
 
.PHONY: all clean
