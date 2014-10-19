// reflector.hpp

/////////////////////////////////////////////////////////////////////////
// Declarations of the reflector class members. /////////////////////////
/////////////////////////////////////////////////////////////////////////

#ifndef REFLECTOR_H_
#define REFLECTOR_H_

#include <fstream>
#include <array>

#include "encryptor.hpp"

class Reflector : public Encryptor
{
    private:
        const int REFLECTOR_OFFSET = 13;

    public:
        // Destructor.
        ~Reflector();

        // Let A = { x :: unsigned int | 0 <= x <= 25 }.
        // Let f :: A -> A, a bijective, self-inverse function which 
        // represents the reflector-specific mapping. f = f^(-1)
        // f x = (x + REFLECTOR_OFFSET) % ALPHABET_LENGTH
        int f(const int) override;
    
};

#endif // REFLECTOR_H_
