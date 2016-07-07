#include "readatomslinks.h"
#include "limits.h"
#include "spin.h"
#include "magnetization.h"

double compute_magnetization (
	const std::vector<Atom>& atoms,
    const std::vector<Spin>& spins,
    const CSRMatrix& csr
)
{
	double magnetization{0};

	for (size_t i = 0; i < spins.size(); ++i)
    {
        magnetization += spins[i];
    }

    return magnetization;
}