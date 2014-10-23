// plugboard.hpp

/////////////////////////////////////////////////////////////////////////
// Declarations of the plugboard class members. /////////////////////////
/////////////////////////////////////////////////////////////////////////

#ifndef PLUGBOARD_H_
#define PLUGBOARD_H_

#include <iostream>
#include <array>

#include "encryptor.hpp"

namespace Enigma 
{
    class Plugboard : public Encryptor
    {
        public:
            // Constructor and destructor.
            Plugboard(char*);
            ~Plugboard();

            // The plugboard map. 
            int f(const int) override;

        private:
            // Array implementation of the map..
            std::array<int, ALPHABET_LENGTH> map;

        public:
            // Overriding the << operator.
            friend std::ostream& operator<<(std::ostream&, const Plugboard&);

    };

}

#endif // PLUGBOARD_H_
