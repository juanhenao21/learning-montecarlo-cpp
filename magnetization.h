#ifndef MAGNETIZATION_H_
#define MAGNETIZATION_H_

#include <cmath>
#include <fstream>
#include <iostream>

#include "limits.h"
#include "readatomslinks.h"
#include "spin.h"

double compute_magnetization (
	const std::vector<Spin>& spins
);

#endif