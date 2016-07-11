#include "readatomslinks.h"
#include "limits.h"
#include "spin.h"
#include "energy.h"

//std::vector<Atom> atoms;

/**
 * Computes the energy of the system.
 * <p>
 * Using the atom, the spin and the neighbors, it is computed the energy of the
 * system.
 * @param atoms  vector with the spin values of the atom
 * @param spin  random spin orientation of the atom
 * @param csr  compressed sparse row that contains the information of the atoms' neighbors
 * @return double ener the energy of the system.
 */
double compute_energy (
    const std::vector<Atom>& atoms,
    const std::vector<Spin>& spins,
    const CSRMatrix& csr
)
{
    /** Energy of the system. */
    double ener{0};
    /** Spin value of the atom and the neighbors. */
    double spinValue;

    for (size_t i = 0; i < atoms.size(); ++i)
    {
        for (int j = csr.limits[i] ; j < csr.limits[i+1]; ++j)
        {
            spinValue = spins[i] * spins[csr.neighboors[j]];
            ener -= csr.exchanges[j] * atoms[i].s * atoms[csr.neighboors[j]].s * spinValue;
        }
    }

    return ener * 0.5;
}

double delta_energy (
    const std::vector<Atom>& atoms,
    const std::vector<Spin>& spins,
    const CSRMatrix& csr,
    const Spin& newSpin,
    int pos
)
{
    double energyDiff{0};
    Spin spinDiff = newSpin - spins[pos];

    for (int i = csr.limits[pos] ; i < csr.limits[pos+1]; ++i)
    {
        double spinDot = spinDiff * spins[csr.neighboors[i]];
        energyDiff -= csr.exchanges[i] * atoms[pos].s * atoms[csr.neighboors[i]].s * spinDot;
    }

    return energyDiff;
}