// reflector.hpp

/////////////////////////////////////////////////////////////////////////
// Declarations of the reflector class members. /////////////////////////
/////////////////////////////////////////////////////////////////////////

#ifndef REFLECTOR_H_
#define REFLECTOR_H_

#include "encryptor.hpp"

namespace Enigma
{
	class Reflector : public Encryptor
	{
		private:
			const int REFLECTOR_OFFSET = 13;

		public:
			// Destructor.
			~Reflector();

			// The reflector map.
			int f(const int) override;
		
	};
}

#endif // REFLECTOR_H_
