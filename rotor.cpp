// rotor.cpp

///////////////////////////////////////////////////////////////////
// Definitions of the rotor class members. ////////////////////////
///////////////////////////////////////////////////////////////////

#ifndef ROTOR_C_
#define ROTOR_C_

#include <array>
#include <iostream>
#include <sstream>

#include "rotor.hpp"
#include "util.hpp"

using namespace Enigma; 


///////////////////////////////////////////////////////////////////

// Constructor.

// Let f(x)  = y
// y_pointer the pointer to the mapping of the rotor read from file
// x         iterate increasingly through the xs in the domain of f
Rotor::Rotor(int* y_pointer, int rotor_index)
{
    index  = rotor_index;
	offset = 0;

    for(int x = 0; x < ALPHABET_LENGTH; ++x) 
	{
		map[x] = *(y_pointer + x);
	}
}

// Destructor.
Rotor::~Rotor() {}

///////////////////////////////////////////////////////////////////

// Let A = { x :: unsigned int | 0 <= x < 26 }.
// Let f :: A -> A a bijective function which is used to define the 
//       rotor-specific mapping. The functions f and f_inverse will
//       access the private variable mapping and return the results 
//       of calling f and its inverse f^(-1).

// Implementation of f. Returns the mapping done before reflecting.
// f(x)  = y
int Rotor::f(const int x) 
{
	// PRE: x :: A
    return map[x];
}

// Implementation of f^(-1). Returns the mapping after reflecting.
// f'(x) = y
int Rotor::f_inverse(const int y)
{
	// PRE: y :: A
	int x = 0;
	for(; x < ALPHABET_LENGTH; ++x) if(map[x] == y) break;
	
	if(x >= ALPHABET_LENGTH) throw std::runtime_error("inverse not found"); 
	return x;
}

// Will rotate the rotor by shifting the mapping. Returns whether it
// has reached a full rotation.
bool Rotor::rotate() 
{
	// Shifts right the direct mapping.
	int last  = map[ALPHABET_LENGTH - 1] - 1;
    for(int i = ALPHABET_LENGTH - 1; i > 0; --i) {
		map[i] = Util::decrement(map[i - 1]);
	}
	map[0] = Util::decrement(last); 
	
	++offset;
	if(offset == 26) return true;
	return false;	
}

//////////////////////////////////////////////////////////////////

// Overriding the << operator for printing the class details.
namespace Enigma {
    std::ostream& operator<<(std::ostream& o, const Rotor& r)
    {
        std::ostringstream convert;
        convert << "Rotor number " << r.index << ":\n"
                << "\tRotated by " << r.offset << ";\n"
                << "\tThe mapping is:";
        for(auto i = 0; i < 26; ++i)
        { 
            convert << "\n\tf(" << i << ")\t= " << r.map[i] 
                    << "\tf'(" << r.map[i] << ")\t= " << i ;
        }

        return o << convert.str() << '\n';
    }
}

#endif // ROTOR_C_
