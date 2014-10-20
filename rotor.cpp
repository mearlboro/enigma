// rotor.cpp

/////////////////////////////////////////////////////////////////////////
// Definitions of the rotor class members. //////////////////////////////
/////////////////////////////////////////////////////////////////////////

#ifndef ROTOR_C_
#define ROTOR_C_

#include <array>
#include <iostream>
#include <cstdlib>

#include "rotor.hpp"

using namespace Enigma; 

// Let A = { x :: unsigned int | 0 <= x < 26 }.
// Let f :: A -> A a bijective function which is used to define the 
//       rotor-specific mapping. The functions f and f_inverse will
//       access the private variable mapping and return the results 
//       of calling f and its inverse f^(-1).


// Constructor and destructor.

// Let f(x)  = y
// y_pointer the pointer to the mapping of the rotor read from file
// x         iterate increasingly through the xs in the domain of f

Rotor::Rotor(int* y_pointer, int rotor_index)
{
    // Initialises the object
    index  = rotor_index;
    
    offset = 0;
	notch  = false;

    for(int x = 0; x < 26; ++x) 
    {
        int f_x = *(y_pointer + x);
        mapping[x] = f_x;
        inverse_mapping[f_x] = x;
    }
}

Rotor::~Rotor() {}

// Returns the mapping done before the reflector, with the offset.
int Rotor::f(const int x) 
{
	// PRE:  x    :: A
	// POST: f(x) :: A
    return mapping[x + offset];
}

// Returns the mapping done after the reflector by substracting the 
// offset from the output. 
int Rotor::f_inverse(const int x)
{
	// PRE:  x            :: A
    // POST: f_inverse(x) :: A
    int y = inverse_mapping[x] - offset;
    return (y >= 0) ? y : abs(y);//(abs(y) % ALPHABET_LENGTH);
}

// Setting the notch to true will cause the next rotor to make a rotation.
bool Rotor::get_notch()
{
    return notch; 
}

// Will rotate the rotor by incrementing the offset.
void Rotor::rotate() 
{
    ++offset;
	if(offset == 27) notch = true;	
}

namespace Enigma {
    // Overriding the << operator for printing the details of the class.
    std::ostream& operator<<(std::ostream& o, const Rotor& r)
    {
        std::ostringstream convert;
        convert << "Rotor number " << r.index << ":\n"
                << "\tRotated by " << r.offset << ";\n"
                << "\tThe mapping is:";

        for(auto i = 0; i < 26; i++)
        { 
            convert << "\n\tf(" << i << ")\t= " << r.mapping[i + r.offset] 
                    << "\tf'(" << i << ")\t= " << r.inverse_mapping[i] - r.offset;
        }

        return o << convert.str() << '\n';
    }
}

#endif // ROTOR_C_
