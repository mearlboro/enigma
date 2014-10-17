// encryptor.hpp

/////////////////////////////////////////////////////////////////////////
// Abstract base class for the rotor, reflector and plugboard classes. //
/////////////////////////////////////////////////////////////////////////

#pragma once // optional

#ifndef ENCRYPTOR_H_
#define ENCRYPTOR_H_

#include <cstdint>
#include <ifstream>
#include <array>

class Encryptor
{
  public:
    // Virtual constructor and destructor.
    virtual Encryptor(const *FILE);
    virtual ~Encryptor();

    // The pure virtual functions f and f_inverse will be overriden
    // accordingly to simulate the specific mapping behaviours 
    // displayed by the three Encryptor sub-classes.
    virtual uint8_t f(const uint8_t) const = 0;


  private:
    // Constant to set the length of the Enigma machine alphabet.
    const ALPHABET_LENGTH = 26;
    
    // The implementation of the mappings done by the encryptors.    
    std::array<uint8_t, ALPHABET_LENGTH> mapping;
   
};

#endif // ENCRYPTOR_H_
