#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>

#include "types.h"
#include "utilities.h"
#include "limits.h"
#include "energy.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
    	std::cout << "Remember to specify the data file" << std::endl;
    }

    // Data reading
    std::vector<Atom> atoms;
    std::vector<Link> links;

    AtomsLinks al = AtomsLinks::read_from_file(argv[1]);
    atoms = al.atoms;
    links = al.links;

    // Link and Atom ordering
    std::sort(links.begin(), links.end(), CompLink());
    std::sort(atoms.begin(), atoms.end(), CompAtom());

    // CSR (Compressed Sparse Row) representation
    // Neighboors, interactions and limits
    Link link;
    
    CSRMatrix csr = get_limits(links);

    // Energy calculation
    double Energy;
	Energy = energy(atoms, csr);

	std::cout << "Energy = " << -Energy << std::endl;    
}
