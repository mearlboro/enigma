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

std::vector<Rotor*> rotors;
int no_rotors;
Reflector* re;
Plugboard* p;
int to_rotate;
std::vector<int> word;


void print_rotors();
 
void enigma_init(int n_r, char** argv) {
    int n[26];
    no_rotors = n_r;

    re = new Reflector();
    to_rotate = 0;

    for(auto i = 1; i <= no_rotors; i++) // i starts from 1 because 
    {                                   // files start from argv[1]
        int l = 0; 
        Rotor* r = new Rotor(Util::read_file(argv[i], n, l), i);
        rotors.push_back(r);
    }

    int l = 0;
    p = new Plugboard(Util::read_file(argv[n_r + 1], n, l), l);
}

void print_rotors()
{
    for(Rotor* r : rotors)
        std::cout<<*r;
}

void enigma_encode(int &x)
{
    // Plugboard.
    x = p->f(x);

    // Forward through the rotors.
	if(no_rotors) {
    	for(Rotor *r : rotors) x = r->f(x);
    }
    // Reflector.
    x = re->f(x);

    // Backwards through the rotors.
    if(no_rotors) {
		std::vector<Rotor*>::reverse_iterator rr;
		for(rr = rotors.rbegin(); rr != rotors.rend(); ++rr)
		{
			x = (*rr)->f_inverse(x);
		}
	}

    // Plugboard.
    x = p->f(x);

    // Rotate rotor.
    if(no_rotors) {
		if(rotors[to_rotate]->rotate()) ++to_rotate;
	}
}

int main(int argc, char** argv)
{
    enigma_init(argc - 2, argv); // first is program name, last is pb.

    char C;
    while(std::cin>>C) 
    {
        int x = Util::ctoa(C);
        if(0 <= x && x < 26) enigma_encode(x);
		std::cout << Util::atoc(x);
    }
    return 0;
}

