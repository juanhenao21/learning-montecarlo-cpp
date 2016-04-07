#include "limits.h"


std::vector<int> get_limits (const std::vector<Link>& links)
{
    int a{0};
    int n{0};

    std::vector<int> limits;
    std::vector<int> neighboors;
    std::vector<int> interactions;

    limits.push_back(n);
    for (int i = 0; i < links.size();)
    {
        do
        {
            n++;
            i++;
            neighboors.push_back(links[i].target);
            interactions.push_back(links[i].exchange);
        }
        while (links[i].source == a);

        a += 1;
        limits.push_back(n);
    }

    return limits;
}
