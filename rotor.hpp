// rotor.hpp

/////////////////////////////////////////////////////////////////////////
// Declarations of the rotor class members. /////////////////////////////
/////////////////////////////////////////////////////////////////////////

#ifndef ROTOR_H_
#define ROTOR_H_

#include <iostream>
#include <array>

#include "encryptor.hpp"

namespace Enigma
{
    class Rotor : public Encryptor
    {
        public:
            // Constructor and destructor.
            Rotor(char*);
            ~Rotor();

            // The rotor map and inverse map. 
            int f(const int) override;

            int f_inverse(const int);

            // Rotates the rotor whenever a character is encoded.
            bool rotate();

        private: 
            // Array implementation of the function.
            std::array<int, ALPHABET_LENGTH> map;

            // Integer value to specify the number of times it has rotated.
            int offset;

        public:
            // Overriding the << operator.
            friend std::ostream& operator<<(std::ostream&, const Rotor&);

    };
}

#endif // ROTOR_H_
