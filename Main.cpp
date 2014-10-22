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

const int n_rotors;

std::vector<Rotor*> rs;
Reflector* re;
Plugboard* p;
std::vector<int> word;


void print_rotors();
 
void enigma_init(int argc, char** argv) {
    int n[26];
    n_rotors = argc - 2; // First argument is program name, last is
						 // .pb, the rest are .rot.

    re = new Reflector();

    for(int i = 1; i <= n_rotors; ++i)  // i starts from 1 because 
    {                                   // files start from argv[1]
        int l = 0; 
        Rotor* r = new Rotor(Util::read_file(argv[i], n, l), i);
        rs.push_back(r);
    }

    int l = 0;
    p = new Plugboard(Util::read_file(argv[argc - 1], n, l), l);
}

void print_rotors()
{
	foreach(r,rs)
        std::cout<<r;
	foreach_r(r,rs) 
        std::cout<<*r;
}

void enigma_encode(int &x)
{
    // Plugboard.
    x = p->f(x);
	std::cout<<x<<"->";
    // Forward through the rotors.
	if(no_rotors) {
    	foreach(r, rs) x = (*r)->f(x);
	std::cout<<x<<"->";
    }
    // Reflector.
    x = re->f(x);
	std::cout<<x<<"->";

    // Backwards through the rotors.
    if(no_rotors) {
		foreach_r(r, rs)
		{
			x = (*r)->f_inverse(x);
	std::cout<<x<<"->";
		}
	}

    // Plugboard.
    x = p->f(x);
	std::cout<<x<<"->";

    // Rotate rotor.
    if(no_rotors) {
		int i = 1; 
		while(rs[i]->rotate()) ++i;//{ std::cout<<"\nRotor rotated "<<i<<'\n'; ++i;}
	}
	
}

int main(int argc, char** argv)
{
    enigma_init(argc, argv); // first is program name, last is pb.
//	int i;
	print_rotors();
//	while(std::cin>>i) { std::cout<<rs[1]->f_inverse(i); }
    char C;
	int x;
    while(std::cin>>C)
    { 
		std::cout<<"muje";
		if(0 <= x && x < 26) 
		{
			std::cout<<"muje";
			x = Util::ctoa(C);
        	enigma_encode(x);
			std::cout << Util::atoc(x);
	    }
		else std::cout<<"invalid input";
    }
    return 0;
}

