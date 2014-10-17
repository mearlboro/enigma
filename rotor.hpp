// rotor.hpp

/////////////////////////////////////////////////////////////////////////
// Declarations of the rotor class members. /////////////////////////////
/////////////////////////////////////////////////////////////////////////

#pragma once // optional

#ifndef ROTOR_H_
#define ROTOR_H_

#include <cstdint>
#include <ifstream>
#include <array>

#include "encryptor.hpp"

class Rotor : public Encryptor
{
  public:
    // Constructor and destructor.
    Rotor(const *FILE);
    ~Rotor();

    // Let A = { x :: unsigned int | 0 <= x <= 25 }.
    // Let f :: A -> A, a bijective function which represents the 
    // rotor-specific mapping. The functions f and f_inverse will
    // access the private variable mapping and return the results 
    // of calling f and its inverse f^(-1).
    uint8_t f(const uint8_t) override;

    uint8_t f_inverse(const uint8_t);

    // Rotor specific functions. Will get and set the value of
    // the notch.
    void set_notch();
    bool get_notch();

    // Function to rotate the rotor
    void rotate(); 

 
  private: 
    // Boolean value to specify whether the notch that makes the 
    // next rotor to rotate by one position is in position.
    bool notch;

    // Integer value to specify the offset by which the rotor has
    // been moved, offset :: A.
    uint8_t offset;

};

#endif // ROTOR_H_
