// machine.hpp 

///////////////////////////////////////////////////////////////////
// Declarations of the enigma machine class members. //////////////
///////////////////////////////////////////////////////////////////

#ifndef MACHINE_H_
#define MACHINE_H_

#include <vector>
#include "util.hpp"
#include "util.cpp"

#include "reflector.hpp"
#include "reflector.cpp"
#include "rotor.hpp"
#include "rotor.cpp"
#include "plugboard.hpp"
#include "plugboard.cpp"

namespace Enigma
{
    class Machine 
    {
        public:
            // Constructor and destructor.
            Machine(int, char**);
            ~Machine();

            // Encodes the given input.
            void encode(int&);        

            // Cascades the rotations.
            void cascade();

        private:
            // Number of rotors in the machine.
            int rotors;

            // The components.
            std::vector<Rotor*> rs;
            Reflector* re;
            Plugboard* p;

        public:
            //Overriding the << operator.
            friend std::ostream& operator<<(std::ostream&, const Machine&);
    };
}

#endif // MACHINE_H_
