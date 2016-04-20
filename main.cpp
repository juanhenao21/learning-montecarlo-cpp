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

    // Energy calculation

    // Change of the spin with an random spin and energy calculation

    int TempMax{50};
    for (int Temp = 0; Temp <= TempMax; Temp += 5)
    {
        std::vector<Spin> state(al.natoms(), Spin::null());

        SpinGenerator randSpinGen(2);
        std::generate(state.begin(), state.end(), randSpinGen);

        double energy;
        energy = compute_energy(atoms, state, csr);
        int natoms{al.natoms()};
        std::ofstream myfile;
        myfile.open ("metropolis" + std::to_string(Temp) + ".dat");
        myfile << energy << "\n";

        long int changes{1000000};
        double energyAfter, energyBefore{energy};
        std::vector<Spin> stateBefore (state);
        std::vector<Spin> stateAfter (state);
        for (int i = 0; i < changes; ++i)
        {
            std::random_device rd;
            std::mt19937 a(rd());
            std::uniform_int_distribution<> dis(0, natoms-1);
            int randval{dis(a)};

            Spin aleatorio = Spin::randSpin();
            stateAfter[randval] = aleatorio;

            energyAfter = compute_energy(atoms, stateAfter, csr);

            if (energyAfter < energyBefore)
            {
                myfile << energyAfter << "\n";
                energyBefore = energyAfter;
                stateBefore = stateAfter;
            }
            else
                std::random_device rd;
                std::mt19937 b(rd());
                std::uniform_real_distribution<> met(0, 1);
                if (exp(- (energyAfter - energyBefore)/Temp) >= met(b))
                {
                    myfile << energyAfter << "\n";
                    energyBefore = energyAfter;
                    stateBefore = stateAfter;
                }
                else
                    myfile << energyBefore << "\n";
        }

        myfile.close();
    }
    
}
