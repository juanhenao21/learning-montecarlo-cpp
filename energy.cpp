#include <iostream>

#include "types.h"
#include "limits.h"

std::vector<Atom> atoms;

double energy (const std::vector<Atom>& atoms, const CSRMatrix& csr)
{
    Spin sup = Spin::up();
    double Ener{0};

    for (int i = 0; i < atoms.size(); ++i)
    {
        for (int j = csr.limits[i] ; j < csr.limits[i+1]; ++j)
        {
            Ener -= csr.exchanges[j] * atoms[i].s * atoms[csr.neighboors[j]].s;
        }
    }

    return Ener;
}