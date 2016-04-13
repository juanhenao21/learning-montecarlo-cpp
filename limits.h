#ifndef LIMITS_H_
#define LIMITS_H_

#include <algorithm>
#include <vector>

#include "types.h"
#include "utilities.h"

struct CSRMatrix {
    std::vector<int> limits;
    std::vector<int> neighboors;
    std::vector<float> exchanges;

    /**
      * This function builds a CSRMatrix out of a list of links
      *
      * @param links: list of links
      */
    static CSRMatrix build_from_links (const std::vector<Link>& links);
};

#endif
