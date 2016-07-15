#include "readatomslinks.h"
#include "limits.h"
#include "spin.h"
#include "energy.h"
#include "metropolis.h"
#include "temploop.h"

void temploop(
	int tempMax,
	int tempStep,
	const std::vector<Atom>& atoms,
    const ReadAtomsLinks& al,
    long int iterations,
    const CSRMatrix& csr
)
{
	for (int Temp = tempMax; Temp >= 0; Temp -= tempStep)
    {        
    	metropolis(Temp, atoms, al, iterations, csr);
    }
}