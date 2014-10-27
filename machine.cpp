// machine.cpp

///////////////////////////////////////////////////////////////////
// Definitions of the enigma machine class member. ////////////////
///////////////////////////////////////////////////////////////////
 
#ifndef MACHINE_C_
#define MACHINE_C_

#include <iostream>
#include <vector>
#include "util.hpp"
#include "util.cpp"

#include "reflector.hpp"
#include "reflector.cpp"
#include "rotor.hpp"
#include "rotor.cpp"
#include "plugboard.hpp"
#include "plugboard.cpp"

#include "machine.hpp"

using namespace Enigma;

///////////////////////////////////////////////////////////////////

// Constructor.
Machine::Machine(int argc, char** argv) {
    rotors = argc - 2; // First argument is program name, last is
          						 // .pb, the rest are .rot.

    re = new Reflector();

    for(int i = 1; i <= rotors; ++i) 
    {
        Rotor* r = new Rotor(argv[i]);
        rs.push_back(r);
    }

    p = new Plugboard(argv[argc - 1]);
}

// Destructor.
Machine::~Machine() {}

///////////////////////////////////////////////////////////////////

// Encodes the referenced value x.
void Machine::encode(int &x)
{
    // Plugboard.
    x = p->f(x);

    // Forward through the rotors.
    if(rotors) 
	{
        for(Rotor* r: rs)
		{
		    x = r->f(x);
		}
    }

    // Reflector.
    x = re->f(x);

    // Backwards through the rotors.
    if(rotors) 
	{
		for(int i= rotors - 1; i >= 0; --i) 
		{
			x = rs[i]->f_inverse(x);
		}
	}

    // Plugboard.
    x = p->f(x);
}

// Rotates the rotors.
void Machine::cascade() 
{
	if(rotors) 
	{
		int i = 0;
		while(rs[i]->rotate() && i < rotors - 1) ++i;
	}
}

//////////////////////////////////////////////////////////////////

// Overriding the << operator for printing the class details.
/*namespace Enigma 
{
    std::ostream& operator<<(std::ostream& o, const Machine& m)
    {
        std::ostringstream convert;
        convert << "Enigma Machine\nPlugboard:" << m.p << "\nReflector:"
                << m.re << "\nRotors:";
        for(int i = 0; i < m.rotors; ++i) convert << m.rs[i];

        return o << convert.str() << '\n';
    }
}*/

#endif // MACHINE_C_
