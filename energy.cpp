#include <iostream>

#include "types.h"
#include "limits.h"

std::vector<Atom> atoms;

double compute_energy (const std::vector<Atom>& atoms, const std::vector<Spin>& spins, const CSRMatrix& csr)
{
    double Ener{0};
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