#ifndef ENERGY_H_
#define ENERGY_H_

#include <cmath>
#include <fstream>
#include <iostream>

#include "limits.h"
#include "readatomslinks.h"
#include "spin.h"

double compute_energy (const std::vector<Atom>& atoms, const std::vector<Spin>& spins,
                        const CSRMatrix& csr);


void metropolis(
    int tempMax,
    const std::vector<Atom>& atoms,
    const ReadAtomsLinks& al,
    long int iterations,
    const CSRMatrix& csr
);


#endif
