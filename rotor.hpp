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
            // access the private mapping variable and return the results
            // of calling f and its inverse f^(-1).
            int f(const int) override;

            int f_inverse(const int);

            // Rotates the rotor whenever a character is encoded.
            bool rotate();

            // Overriding the << operator.
            friend std::ostream& operator<<(std::ostream&, const Rotor&);

        private: 
            // Array implementations of the functions f and f^(-1).
            std::array<int, ALPHABET_LENGTH> map;

			// Integer value to specify the number of times it has rotated.
			int offset;

            // Integer value to specify the index of this rotor in the
            // machine.
            int index;
    };
}

#endif // ROTOR_H_
