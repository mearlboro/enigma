// plugboard.hpp

/////////////////////////////////////////////////////////////////////////
// Declarations of the plugboard class members. /////////////////////////
/////////////////////////////////////////////////////////////////////////

#ifndef PLUGBOARD_H_
#define PLUGBOARD_H_

#include <cstdint>
#include <fstream>
#include <array>

#include "encryptor.hpp"

namespace Enigma 
{
    class Plugboard : public Encryptor
    {
        public:
            // Constructor and destructor.
            Plugboard(int*, int);
            ~Plugboard();

            // Let A = { x :: unsigned int | 0 <= x <= 25 }.
            // Let f :: A -> A, a bijective, self-inverse function which 
            // represents the plugboard-specific mapping. The function f
            // will access the private variable mapping.
            int f(const int) override;

            // Overriding the << operator.
            friend std::ostream& operator<<(std::ostream&, const Plugboard&);

        private:
            // Array implementation of the function f.
            std::array<int, ALPHABET_LENGTH> mapping;
    };

}

#endif // PLUGBOARD_H_
