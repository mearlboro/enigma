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


Plugboard::Plugboard(char* file) 
{
    // Initialise the mapping to identity mapping.
    for(int x = 0; x < ALPHABET_LENGTH; ++x) mapping[x] = x;

    // Add the self-inverse entries read from the file.
	std::vector<int> y = Util::read_file(file);
	int n = y.size() / 2;
    for(int i = 0; i < n; ++i)
    {
        int x   = y[i * 2];
        int f_x = y[i * 2 + 1];
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
