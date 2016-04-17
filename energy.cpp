#include <iostream>

#include "readatomslinks.h"
#include "limits.h"
#include "spin.h"

std::vector<Atom> atoms;

/**
 * Computes the energy of the system.
 * <p>
 * Using the atom, the spin and the neighbors, it is computed the energy of the system.
 * @param atoms  vector with the spin values of the atom
 * @param spin  random spin orientation of the atom
 * @param csr  compressed sparse row that contains the information of the atoms' neighbors
 * @return double Ener the energy of the system.
 */
double compute_energy (const std::vector<Atom>& atoms, const std::vector<Spin>& spins, const CSRMatrix& csr)
{
    /** Energy of the system. */
    double Ener{0};
    /** Spin value of the atom and the neighbors. */
    double SpinValue;

    for (int i = 0; i < atoms.size(); ++i)
    {
        for (int j = csr.limits[i] ; j < csr.limits[i+1]; ++j)
        {
            SpinValue = spins[i] * spins[csr.neighboors[j]];
            Ener -= csr.exchanges[j] * atoms[i].s * atoms[csr.neighboors[j]].s * SpinValue;
        }
    }

    return Ener;
}