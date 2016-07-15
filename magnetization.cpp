#include "readatomslinks.h"
#include "limits.h"
#include "spin.h"
#include "magnetization.h"

double compute_magnetization (
	const std::vector<Spin>& spins
)
{
	float magnetization{0};

	Spin sumMag = Spin::null();

	for (size_t i = 0; i < spins.size(); ++i)
    {
        sumMag = sumMag + spins[i];
    }

    magnetization = Spin::normSpin(sumMag/spins.size());

    return magnetization;
}