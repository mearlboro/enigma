// reflector.cpp

///////////////////////////////////////////////////////////////////
// Definitions of the reflector class members. ////////////////////
///////////////////////////////////////////////////////////////////

#ifndef REFLECTOR_C_
#define REFLECTOR_C_

#include <sstream>

#include "reflector.hpp"

using namespace Enigma;


//////////////////////////////////////////////////////////////////

// Destructor.
Reflector::~Reflector() {}

//////////////////////////////////////////////////////////////////

// Let A = { x :: unsigned int | 0 <= x <= 25 }.
// Let f :: A -> A, a bijective, self-inverse function which
//       represents the reflector-specific mapping. f = f^(-1)

// f x = (x + REFLECTOR_OFFSET) % ALPHABET_LENGTH
int Reflector::f(const int x)
{
    // PRE: x :: A
    return (x + Reflector::REFLECTOR_OFFSET) % 
            Reflector::ALPHABET_LENGTH;
}

//////////////////////////////////////////////////////////////////

// Overriding the << operator for printing the class details.
namespace Enigma 
{
    std::ostream& operator<<(std::ostream& o, const Reflector& r)
    {
        std::ostringstream convert;
        convert << "Reflector:\n\tThe mapping is:\nf(x) = (x + " 
                << r.REFLECTOR_OFFSET << ") mod " << r.ALPHABET_LENGTH;

        return o << convert.str() << '\n';
    }
}

#endif // REFLECTOR_C_
