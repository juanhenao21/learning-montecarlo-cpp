/**
 * <h1> Data reading and Energy calculation </h1>
 * This program reads a data file input, store the
 * information in CSR (Compressed Sparse Row) representation
 * and compute the energy of the system.
 *
 * @author Juan Camilo Henao Londoño
 * @author Oscar David Arbelaez Echeverri
 * @version 0.0
 * @since 2016-04
 */

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

/*
 * This is the main function of the program which reads,
 * create the CSR representation and compute the energy
 * of the system.
 * @param argv[] Input data file.
 * @return int This returns zero if everything went ok.
 */
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

    SpinGenerator randSpinGen(2);
    SpinGenerator upSpinGen(0);

    std::cout << randSpinGen() << std::endl;
    std::cout << randSpinGen() << std::endl;
    std::cout << upSpinGen() << std::endl;

    std::generate(spins.begin(), spins.end(), randSpinGen);

    /* std::cout << spins << std::endl; */

    // Energy calculation
    double energy;
    energy = compute_energy(atoms, spins, csr);

    std::cout << "Energy = " << energy << std::endl;
}
