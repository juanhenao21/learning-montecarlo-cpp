#ifndef ENERGY_H_
#define ENERGY_H_ 

#include "types.h"
#include "limits.h"

double energy (const std::vector<Atom>& atoms, const CSRMatrix& csr);

#endif