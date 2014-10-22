// util.hpp

//////////////////////////////////////////////////////////////////
// Definitions of the util class. ////////////////////////////////
//////////////////////////////////////////////////////////////////

#ifndef UTIL_H_
#define UTIL_H_

namespace Enigma 
{
	class Util
	// Contains basic helper functionalities as static functions.
	{
		public:
			static int *read_file(char*, int*, int&);

			static int ctoa(char);

			static char atoc(int);

			static int decrement(int);
	};
}

# endif // UTIL_H_
