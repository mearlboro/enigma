// rotor.hpp

/////////////////////////////////////////////////////////////////////////
// Declarations of the rotor class members. /////////////////////////////
/////////////////////////////////////////////////////////////////////////

#ifndef ROTOR_H_
#define ROTOR_H_

#include <array>
#include <cstdint>

#include "encryptor.hpp"

namespace Enigma {
    class Rotor : public Encryptor
    {
        public:
            // Constructor and destructor.
            Rotor(int*, int);
            ~Rotor();

            // Let A = { x :: unsigned int | 0 <= x <= 25 }.
            // Let f :: A -> A, a bijective function which represents the
            // rotor-specific mapping. The functions f and f_inverse will
            // access the private variable mapping and return the results
            // of calling f and its inverse f^(-1).
            int f(const int) override;

            int f_inverse(const int);

            // Rotor specific functions. Will set the value of the notch.
            bool get_notch();
            
            // Rotates the rotor whenever a character is encoded.
            void rotate();

            // Overriding the << operator.
            friend std::ostream& operator<<(std::ostream&, const Rotor&);

        private: 
            // Array implementations of the functions f and f^(-1).
            std::array<int, ALPHABET_LENGTH> mapping;
            std::array<int, ALPHABET_LENGTH> inverse_mapping;

            // Boolean value to specify whether the notch that makes the 
            // next rotor to rotate by one position is in position.
            // bool notch;

            // Integer value to specify the offset by which the rotor has
            // been moved, offset :: A.
            int offset;

            // Integer value to specify the index of this rotor in the
            // machine.
            int index;
    };
}

#endif // ROTOR_H_
