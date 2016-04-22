#include <iostream>

#include "readatomslinks.h"
#include "limits.h"
#include "spin.h"
#include "energy.h"

std::vector<Atom> atoms;

/**
 * Computes the energy of the system.
 * <p>
 * Using the atom, the spin and the neighbors, it is computed the energy of the system.
 * @param atoms  vector with the spin values of the atom
 * @param spin  random spin orientation of the atom
 * @param csr  compressed sparse row that contains the information of the atoms' neighbors
 * @return double ener the energy of the system.
 */
double compute_energy (const std::vector<Atom>& atoms, const std::vector<Spin>& spins,
                        const CSRMatrix& csr)
{
    /** Energy of the system. */
    double ener{0};
    /** Spin value of the atom and the neighbors. */
    double SpinValue;

    for (size_t i = 0; i < atoms.size(); ++i)
    {
        for (int j = csr.limits[i] ; j < csr.limits[i+1]; ++j)
        {
            SpinValue = spins[i] * spins[csr.neighboors[j]];
            ener -= csr.exchanges[j] * atoms[i].s * atoms[csr.neighboors[j]].s * SpinValue;
        }
    }

    return ener;
}


/**
 * Metropolis Algorithm.
 * <p>
 * Setting a .
 * @param atoms  vector with the spin values of the atom
 * @param spin  random spin orientation of the atom
 * @param csr  compressed sparse row that contains the information of the atoms' neighbors
 * @return double ener the energy of the system.
 */
void metropolis(
    int TempMax,
    const std::vector<Atom>& atoms,
    const ReadAtomsLinks& al,
    long int iterations,
    const CSRMatrix& csr
)
{
    int natoms{al.natoms()};
    std::mt19937 sequence;
    std::uniform_int_distribution<> dis(0, natoms-1);
    std::uniform_real_distribution<> met(0, 1);

    for (int Temp = 0; Temp <= TempMax; Temp += 5)
    {
        std::vector<Spin> state(al.natoms(), Spin::null());

        SpinGenerator randSpinGen(2);
        std::generate(state.begin(), state.end(), randSpinGen);

        double energy;
        energy = compute_energy(atoms, state, csr);
        std::ofstream myfile;
        myfile.open ("metropolis" + std::to_string(Temp) + ".dat");
        myfile << energy << "\n";

        double energyAfter, energyBefore{energy};
        std::vector<Spin> stateBefore (state);
        std::vector<Spin> stateAfter (state);


        for (int i = 0; i < iterations; ++i)
        {
            int randval{dis(sequence)};

            Spin aleatorio = Spin::randSpin(sequence);
            stateAfter[randval] = aleatorio;

            energyAfter = compute_energy(atoms, stateAfter, csr);

            if (energyAfter < energyBefore)
            {
                myfile << energyAfter << "\n";
                energyBefore = energyAfter;
                stateBefore = stateAfter;
            }
            else
            {
                if (exp(- (energyAfter - energyBefore)/Temp) >= met(sequence))
                {
                    myfile << energyAfter << "\n";
                    energyBefore = energyAfter;
                    stateBefore = stateAfter;
                }
                else
                {
                    myfile << energyBefore << "\n";
                }
            }
        }

        myfile.close();
    }
}
