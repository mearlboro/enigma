// util.hpp

//////////////////////////////////////////////////////////////////
// Definitions of the util class. ////////////////////////////////
//////////////////////////////////////////////////////////////////

#ifndef UTIL_H_
#define UTIL_H_

#include <vector>

namespace Enigma 
{
	class Util
	// Contains basic helper functionalities as static functions.
	{
		public:
			static std::vector<int> read_file(char*);

			static int ctoa(char);

			static char atoc(int);

			static int decrement(int);
	};
}

# endif // UTIL_H_
