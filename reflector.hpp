// reflector.hpp

/////////////////////////////////////////////////////////////////////////
// Declarations of the reflector class members. /////////////////////////
/////////////////////////////////////////////////////////////////////////

#pragma once // optional

#ifndef REFLECTOR_H_
#define REFLECTOR_H_

#include <cstdint>
#include <ifstream>
#include <array>

#include "encryptor.hpp"

class Reflector : public Encryptor
{
  public:
    // Constructor and destructor.
    Reflector(const *FILE);
    ~Reflector();

    // Let A = { x :: unsigned int | 0 <= x <= 25 }.
    // Let f :: A -> A, a bijective, self-inverse function which 
    // represents the reflector-specific mapping. f = f^(-1)
    // The function f will access the private variable mapping.
    int8_t f(const uint8_t) override;

};

#endif // REFLECTOR_H_
