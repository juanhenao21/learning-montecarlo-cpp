#include "readatomslinks.h"
#include "limits.h"
#include "spin.h"
#include "energy.h"
#include "metropolis.h"

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
    int temp,
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
    

    std::ofstream Enerfile;
    std::ofstream Magfile;
    Enerfile.open ("Experiments/energiasWOW.dat");
    Magfile.open ("Experiments/magnetizacionWOW.dat");

    Enerfile << energy << "\n";
    std::cout << "Temperature = " << temp << std::endl;

    for (int i = 0; i < iterations; ++i)
    {
        int site{dis(sequence)};

        Spin aleatorio = Spin::randSpin(sequence);

        double energyDiff = delta_energy(atoms, state, csr, aleatorio, site);

        if (energyDiff < 0)
        {
            state[site] = aleatorio;
            energy += energyDiff;
            Enerfile << energy << "\n";
        }
        else
        {
            if (std::exp(- (energyDiff)/temp) >= met(sequence))
            {
                state[site] = aleatorio;
                energy += energyDiff;
                Enerfile << energy << "\n";
            }
            else
            {
                Enerfile << energy << "\n";
            }
        }
    
    Enerfile.close();

    }
}