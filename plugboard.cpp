// plugboard.cpp

/////////////////////////////////////////////////////////////////////////
// Definitions of the plugboard class members. //////////////////////////
/////////////////////////////////////////////////////////////////////////

#ifndef PLUGBOARD_C_
#define PLUGBOARD_C_

#include <iostream>
#include <sstream>
#include "util.hpp"

#include "plugboard.hpp"

using namespace Enigma;


///////////////////////////////////////////////////////////////////

// Constructor.

// file contains pairs (x, y) such that f(x) = y && f(y) = x 
Plugboard::Plugboard(char* file) 
{
    for(int x = 0; x < ALPHABET_LENGTH; ++x) map[x] = x;

	std::vector<int> y = Util::read_file(file);

	int n = y.size() / 2;  
    for(int i = 0; i < n; ++i)
    {
        int x    = y[i * 2];
        int f_x  = y[i * 2 + 1];
        map[x]   = f_x;
        map[f_x] = x;
    }
}

// Destructor.
Plugboard::~Plugboard() {}

///////////////////////////////////////////////////////////////////

// Let A = { x :: int | 0 <= x < 26 }.
// Let f :: A -> A a bijective function which is used to define the 
//       plugboard-specific mapping. The function f will access the
//       private mapping variable.

int Plugboard::f(const int x) 
{
    // PRE: x :: A
    return map[x];
}

//////////////////////////////////////////////////////////////////

// Overriding the << operator for printing the class details.
namespace Enigma 
{
    std::ostream& operator<<(std::ostream& o, const Plugboard& p)
    {
        std::ostringstream convert;
        convert << "Plugboard:\n\tThe mapping is:";
        for(auto i = 0; i < 26; i++)
        {
            convert << "\n\tf(" << i << ")\t= " << p.map[i];
        }

        return o << convert.str() << '\n';
    }
}

#endif // PLUGBOARD_C_
