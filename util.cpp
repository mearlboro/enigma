// util.cpp

//////////////////////////////////////////////////////////////////
// Declarations of the util class. ///////////////////////////////
//////////////////////////////////////////////////////////////////

#ifndef UTIL_C_
#define UTIL_C_

#include <fstream>

#include "util.hpp"

using namespace Enigma; 


// Reads the content of a .pb or .rot file and returns an array 
// representing the mapping.

// file the string containing the filename.
// n    
std::vector<int> Util::read_file(char* file)
{
	std::vector<int> y;

	std::ifstream fin(file);
	if(fin)
	{
		int n;
		while (fin >> n) y.push_back(n);
		fin.close();
		return y;
	}
	throw std::runtime_error("fopen failed");
}

// Converts an uppercase character in range 'A'-'Z' to its 
// corresponding index in the alphabet A.
int Util::ctoa(char C)
{
	if(isupper(C))
	{
		return (int)C - ((int)'A');
	}
	throw std::runtime_error("ctoa: invalid input to convert");
}

// Converts a number in range 0-25 to its corresponding character.
char Util::atoc(int x)
{
	if(0 <= x && x < Encryptor::ALPHABET_LENGTH)
	{
		return (char)(x + ((int)'A'));
	}
	throw std::runtime_error("atoc: invalid input to convert");
}

// Decrements a number in alphabet A by 1.
int Util::decrement(int x)
{
	--x;
	return (x >= 0) ? x : (x + Encryptor::ALPHABET_LENGTH);
}

# endif // UTIL_C_
