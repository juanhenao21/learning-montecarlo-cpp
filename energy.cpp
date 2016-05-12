#include "readatomslinks.h"
#include "limits.h"
#include "spin.h"
#include "energy.h"

std::vector<Atom> atoms;

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

/**
 * Metropolis Algorithm.
 * <p>
 * The Metropolis algorithm is used to accept or reject a change in the state
 * of the sample. Randomly changing a spin direction, the energy of the system
 * is computed. If the energy is lower than the energy before the change, the
 * new state is accepted. If not, an exponential function is calculated and
 * compared with a random number between zero and one. If the exponential is
 * greater than the random number the change is accepted. If not the initial
 * state is preserved.
 *
 * @param tempMax  Maximum loop temperature
 * @param atoms  Atom type vector with the characteristics of each atom in the sample
 * @param al  ReadAtomLinks type that contain information about the number of atoms in the sample
 * @param iterations  number of changes of spin direction in each temperature
 * @param csr  compressed sparse row that contains the information of the atoms' neighbors
 */
void metropolis(
    int tempMax,
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
    
    RandomSpinGenerator randSpinGen(sequence);
    std::vector<Spin> state(al.natoms(), Spin::null());
    std::generate(state.begin(), state.end(), randSpinGen);
    double energy = compute_energy(atoms, state, csr);

    for (int Temp = 0; Temp <= tempMax; Temp += 5)
    {

        std::ofstream myfile;
        myfile.open ("Experiments/metropolis" + std::to_string(Temp) + ".dat");
        myfile << energy << "\n";

        for (int i = 0; i < iterations; ++i)
        {
            int site{dis(sequence)};

            Spin aleatorio = Spin::randSpin(sequence);

            double energyDiff = delta_energy(atoms, state, csr, aleatorio, site);

            if (energyDiff < 0)
            {
                state[site] = aleatorio;
                energy += energyDiff;
                myfile << energy << "\n";
            }
            else
            {
                if (std::exp(- (energyDiff)/Temp) >= met(sequence))
                {
                    state[site] = aleatorio;
                    energy += energyDiff;
                    myfile << energy << "\n";
                }
                else
                {
                    myfile << energy << "\n";

                }
            }
        }

        myfile.close();
    }
}
