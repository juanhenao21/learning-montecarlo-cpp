#ifndef ENERGY_H_
#define ENERGY_H_ 

#include "types.h"
#include "limits.h"

double compute_energy (const std::vector<Atom>& atoms, const std::vector<Spin>& spins, const CSRMatrix& csr);

#endif