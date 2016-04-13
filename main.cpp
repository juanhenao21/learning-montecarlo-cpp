#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <cstdlib>

#include "types.h"
#include "utilities.h"
#include "limits.h"
#include "energy.h"


int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Remember to specify the data file" << std::endl;
        std::exit(1);
    }

    // Data reading
    std::vector<Atom> atoms;
    std::vector<Link> links;

    AtomsLinks al = AtomsLinks::read_from_file(argv[1]);
    atoms = al.atoms;
    links = al.links;

    // TODO: find a better place to do this
    std::sort(atoms.begin(), atoms.end(), CompAtom());

    // CSR (Compressed Sparse Row) representation
    // Neighboors, interactions and limits
    Link link;

    CSRMatrix csr = CSRMatrix::build_from_links(links);

    std::vector<Spin> spins(al.natoms(), Spin::null());

    RandomSpinGenerator randSpinGen;
    std::vector<Spin> randSpin = std::generate(spins.begin(), spins.end(), randSpinGen.RandomSpinGenerator(2));

    std::cout << spins << std::endl;

    // Energy calculation
    double energy;
    energy = compute_energy(atoms, randSpin, csr);

    std::cout << "Energy = " << energy << std::endl;
}
