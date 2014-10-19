// plugboard.cpp

/////////////////////////////////////////////////////////////////////////
// Definitions of the plugboard class members. //////////////////////////
/////////////////////////////////////////////////////////////////////////

#ifndef PLUGBOARD_C_
#define PLUGBOARD_C_

#include <fstream>
#include <array>

#include "plugboard.hpp"

using namespace Enigma;

// Let A = { x :: unsigned int | 0 <= x < 26 }.
// Let f :: A -> A a bijective, self-inverse function which is used 
//       to define the plugboard-specific mapping and will access the
//       private variable mapping and to return its result.

// Constructor and destructor.

// Let f(x)  = y
// y_pointer the pointer to the mapping of the plugboard as read 
//           from file
// x         iterate increasingly through the xs in the domain of f
Plugboard::Plugboard(int* y_pointer, int n) 
{
    // Initialise the mapping to identity mapping.
    for(int x = 0; x < 26; ++x) mapping[x] = x;

    // Add the self-inverse entries read from the file.
    for(int i = 0; i < n/2; ++i)
    {
        int x   = *(y_pointer + (i * 2));
        int f_x = *(y_pointer + (i * 2 + 1));
        mapping[x]   = f_x;
        mapping[f_x] = x;
    }
}

Plugboard::~Plugboard() {}

// The definition of the mapping function.
// Let A = { x :: unsigned int | 0 <= x <= 25 }.
int Plugboard::f(const int input) 
{
  // PRE: input :: A
  return mapping[input];
}

namespace Enigma 
{
    std::ostream& operator<<(std::ostream& o, const Plugboard& p)
    {
        std::ostringstream convert;
        convert << "Plugboard:\n\tThe mapping is:";

        for(auto i = 0; i < 26; i++)
        {
            convert << "\n\tf(" << i << ")\t= " << p.mapping[i];
        }

        return o << convert.str() << '\n';
    }

}

#endif // PLUGBOARD_C_
