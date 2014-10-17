// plugboard.hpp

/////////////////////////////////////////////////////////////////////////
// Declarations of the plugboard class members. /////////////////////////
/////////////////////////////////////////////////////////////////////////

#pragma once // optional

#ifndef PLUGBOARD_H_
#define PLUGBOARD_H_

#include <cstdint>
#include <ifstream>
#include <array>

#include "encryptor.hpp"

class Plugboard : public Encryptor
{
  public:
    // Constructor and destructor.
    Plugboard(const *FILE);
    ~Plugboard();

    // Let A = { x :: unsigned int | 0 <= x <= 25 }.
    // Let f :: A -> A, a bijective, self-inverse function which 
    // represents the plugboard-specific mapping. The function f
    // will access the private variable mapping.
    uint8_t f(const uint8_t) override;

};

#endif // PLUGBOARD_H_
