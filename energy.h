#ifndef ENERGY_H_
#define ENERGY_H_ 

#include "readatomslinks.h"
#include "limits.h"
#include "spin.h"

double compute_energy (const std::vector<Atom>& atoms, const std::vector<Spin>& spins,
                        const CSRMatrix& csr);


void metropolis(
    int TempMax,
    const std::vector<Atom>& atoms,
    const ReadAtomsLinks& al,
    long int iterations,
    const CSRMatrix& csr
);


#endif