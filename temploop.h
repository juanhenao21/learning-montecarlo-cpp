#ifndef TEMPLOOP_H_
#define TEMPLOOP_H_

#include <cmath>
#include <fstream>
#include <iostream>

#include "limits.h"
#include "readatomslinks.h"
#include "spin.h"
#include "energy.h"
#include "metropolis.h"

void temploop(
	int tempMax,
	int tempStep,
	const std::vector<Atom>& atoms,
    const ReadAtomsLinks& al,
    long int iterations,
    const CSRMatrix& csr
);

#endif