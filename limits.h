#ifndef LIMITS_H_
#define LIMITS_H_

#include <vector>

#include "types.h"

struct CSRMatrix {
    std::vector<int> limits;
    std::vector<int> neighboors;
    std::vector<float> exchanges;
};

std::vector<int> get_limits (std::vector<Link> link);

#endif
