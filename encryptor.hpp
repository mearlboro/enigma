// encryptor.hpp

/////////////////////////////////////////////////////////////////////////
// Abstract base class for the rotor, reflector and plugboard classes. //
/////////////////////////////////////////////////////////////////////////

#ifndef ENCRYPTOR_H_
#define ENCRYPTOR_H_

#include <fstream>
#include <array>
namespace Enigma
{
    class Encryptor
    {
        public:
            // Virtual destructor.
            virtual ~Encryptor() {}

            // The pure virtual functions f and f_inverse will be overriden
            // accordingly to simulate the specific mapping behaviours 
            // displayed by the three Encryptor sub-classes.
            virtual int f(int) = 0;

        protected:
            // Constant to set the length of the Enigma machine alphabet.
            static const int ALPHABET_LENGTH = 26;

		friend class Util;
    };

}

#endif // ENCRYPTOR_H_
