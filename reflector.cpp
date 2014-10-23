// reflector.cpp

/////////////////////////////////////////////////////////////////////////
// Definitions of the reflector class members. //////////////////////////
/////////////////////////////////////////////////////////////////////////

#ifndef REFLECTOR_C_
#define REFLECTOR_C_

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

#endif // REFLECTOR_C_
