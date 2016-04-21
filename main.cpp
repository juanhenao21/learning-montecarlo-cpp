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
#include <typeinfo>
#include <cstdlib>

#include "readatomslinks.h"
#include "utilities.h"
#include "limits.h"
#include "energy.h"
#include "spin.h"
#include "atoms.h"

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

    ReadAtomsLinks al = ReadAtomsLinks::read_from_file(argv[1]);
    atoms = al.atoms;
    links = al.links;

    // CSR (Compressed Sparse Row) representation
    // Neighboors, interactions and limits

    CSRMatrix csr = CSRMatrix::build_from_links(links);

    // Metropolis Algorithm
    int TempMax{50};
    long int iterations{10000};
    metropolis(TempMax, atoms, al, iterations, csr);
}
