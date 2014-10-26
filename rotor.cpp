// rotor.cpp

///////////////////////////////////////////////////////////////////
// Definitions of the rotor class members. ////////////////////////
///////////////////////////////////////////////////////////////////

#ifndef ROTOR_C_
#define ROTOR_C_

#include <iostream>
#include <sstream>
#include "util.hpp"

#include "rotor.hpp"

using namespace Enigma; 


///////////////////////////////////////////////////////////////////

// Constructor.

// file contains pairs (x, y) such that f(x) = y
Rotor::Rotor(char* file)
{
	offset = 0;

	std::vector<int> y = Util::read_file(file);
    for(int x = 0; x < ALPHABET_LENGTH; ++x) 
	{
		map[x] = y[x];
	}
}

// Destructor.
Rotor::~Rotor() {}

///////////////////////////////////////////////////////////////////

// Let A = { x :: int | 0 <= x < ALPHABET_LENGTH }.
// Let f :: A -> A a bijective function which is used to define the 
//       rotor-specific mapping. The functions f and f_inverse will
//       access the private mapping variable and return the results 
//       of calling f and its inverse f^(-1) = f'

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
	int x;
	for(x = 0; x < ALPHABET_LENGTH; ++x) if(map[x] == y) break;

	if(x >= ALPHABET_LENGTH) throw std::runtime_error("inverse not found"); 
	return x;
}

// Will rotate the rotor by shifting the mapping. Returns whether it
// has reached a full rotation.
bool Rotor::rotate() 
{
	int first = Util::decrement(map[0]);
    for(int i = 0; i < ALPHABET_LENGTH - 1; ++i) {
		map[i] = Util::decrement(map[i + 1]);
	}
	map[ALPHABET_LENGTH - 1] = first; 
	
	++offset;
	if(offset == 26) return true;
	return false;	
}

//////////////////////////////////////////////////////////////////

// Overriding the << operator for printing the class details.
namespace Enigma
{
    std::ostream& operator<<(std::ostream& o, const Rotor& r)
    {
        std::ostringstream convert;
        convert << "Rotor rotated by " << r.offset << ";\n"
                << "\tThe mapping is:";
        for(auto i = 0; i < 26; ++i)
        {
			const int x = i;
            convert << "\n\tf(" << i << ")\t= " << r.map[x];
                 //   << "\tf'(" << i << ")\t= "  << r.f_inverse(x);
        }

        return o << convert.str() << '\n';
    }
}

#endif // ROTOR_C_
