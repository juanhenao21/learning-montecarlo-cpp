#include "limits.h"


CSRMatrix CSRMatrix::build_from_links (const std::vector<Link>& _links)
{
    int a{0};
    int n{0};

    // Link and Atom ordering
    std::vector<Link> links(_links);
    std::sort(links.begin(), links.end(), CompLink());

    std::vector<int> limits;
    std::vector<int> neighboors;
    std::vector<float> exchanges;

    limits.push_back(n);
    for (size_t i = 0; i < links.size();)
    {
        do
        {
            n++;
            i++;
            neighboors.push_back(links[i].target);
            exchanges.push_back(links[i].exchange);
        }
        while (links[i].source == a);

        a += 1;
        limits.push_back(n);
    }

    return CSRMatrix { limits, neighboors, exchanges };
}
