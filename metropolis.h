#ifndef METROPOLIS_H_
#define METROPOLIS_H_

#include <cmath>
#include <fstream>
#include <iostream>

#include "limits.h"
#include "readatomslinks.h"
#include "spin.h"
#include "energy.h"

void metropolis(
    int temp,
    const std::vector<Atom>& atoms,
    const ReadAtomsLinks& al,
    long int iterations,
    const CSRMatrix& csr
);

#endif