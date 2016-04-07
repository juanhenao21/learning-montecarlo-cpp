#include <iostream>

#include "types.h"
#include "limits.h"

std::vector<Atom> atoms;

double energy (std::vector<Atom>& atoms, CSRMatrix& csr)
{
	Spin sup = Spin::up();
    double Ener{0};

    for (int i = 0; i < atoms.size(); ++i)
    {
    	for (int j = 0; j < csr.neighboors.size(); ++j)
    	{
    		Ener += csr.exchanges[j];
    	}
    }
}