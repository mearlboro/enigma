#include <iostream>
#include <vector>

#include "reflector.hpp"
#include "reflector.cpp"
#include "rotor.hpp"
#include "rotor.cpp"
#include "plugboard.hpp"
#include "plugboard.cpp"
#include "util.hpp"
#include "util.cpp"

using namespace Enigma;

int n_rotors;

std::vector<Rotor*> rs;
Reflector* re;
Plugboard* p;
std::vector<int> word;

void enigma_init(int argc, char** argv) {
    n_rotors = argc - 2; // First argument is program name, last is
						 // .pb, the rest are .rot.

    re = new Reflector();

    for(int i = 1; i <= n_rotors; ++i)  // i starts from 1 because 
    {                                   // files start from argv[1]
        Rotor* r = new Rotor(argv[i]);
        rs.push_back(r);
    }

    p = new Plugboard(argv[argc - 1]);
}

void q(int x) { std::cout<<x<<"->"; }
void enigma_encode(int &x)
{
    // Plugboard.
    x = p->f(x);

    // Forward through the rotors.
	if(n_rotors) 
	{
    	for(Rotor* r: rs)
		{
			x = r->f(x);
		}
    }

    // Reflector.
    x = re->f(x);

    // Backwards through the rotors.
    if(n_rotors) 
	{
		for(int i= n_rotors - 1; i >= 0; --i) 
		{
			x = rs[i]->f_inverse(x);
		}
	}

    // Plugboard.
    x = p->f(x);

    // Rotate rotor.
    if(n_rotors) 
	{
		int i = 0;
		while(rs[i]->rotate() && i < n_rotors - 1) ++i;
	}
}

int main(int argc, char** argv)
{
    enigma_init(argc, argv); // first is program name, last is pb.
    char C;
	int x;
    while(std::cin>>C)
	{
		if(isupper(C))
		{
			x = Util::ctoa(C);
        	enigma_encode(x);
			std::cout << Util::atoc(x);
	    }
		else std::cout<<"Invalid input: "<<C;
    }
    return 0;
}

