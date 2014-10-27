#ifndef MAIN_C_
#define MAIN_C_

#include <iostream>
#include <vector>
#include "util.hpp"
#include "util.cpp"

#include "machine.hpp"
#include "machine.cpp"

using namespace Enigma;

int main(int argc, char** argv)
{
    Machine* enigma = new Machine(argc, argv); 

    char C;
  	int x;
    while(std::cin>>C)
  	{
		if(isupper(C))
		{
			x = Util::ctoa(C);
            enigma->encode(x);
			enigma->cascade();
            std::cout << Util::atoc(x);
	    }
		else std::cout << "Invalid input: " << C;
    }
    return 0;
}

#endif // MAIN_C_
