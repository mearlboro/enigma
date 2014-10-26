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
		public:
			// Destructor.
			~Reflector();

			// The reflector map.
			int f(const int) override;

		private:
			const int REFLECTOR_OFFSET = 13;

        public:
             // Overriding the << operator.
             friend std::ostream& operator<<(std::ostream&, const Reflector&);		
	};
}

#endif // REFLECTOR_H_
