// reflector.cpp

/////////////////////////////////////////////////////////////////////////
// Definitions of the reflector class members. //////////////////////////
/////////////////////////////////////////////////////////////////////////

#ifndef REFLECTOR_C_
#define REFLECTOR_C_

#include <cstdint>
#include <fstream>
#include <array>

#include "reflector.hpp"

using namespace Enigma;
  
Reflector::~Reflector() {}

// Definition of the function that performs the mapping.
// Let A = { n :: unsigned int | 0 <= n < ALPHABET_LENGTH }.
int Reflector::f(const int x)
{
    // PRE: x :: A
    // assert(0 <= x && x < 26);
    return (x + Reflector::REFLECTOR_OFFSET) % 
            Reflector::ALPHABET_LENGTH;
}

#endif // REFLECTOR_C_
