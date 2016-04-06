#include <iostream>
#include <vector>

std::vector<int> limitsNeighboorsInteractions (Link link)
{
	int a{0};
	int n{0};

	std::vector<int> limits;
	std::vector<int> neighboors;
    std::vector<int> interactions;

	limits.push_back(n);
    for (int i = 0; i < link.size();)
    {
        do
        {
            n++;
            i++;
            neighboors.push_back(link[i].target);
            interactions.push_back(link[i].exchange);
        } 
        while (link[i].source == a);

        a += 1;
        limits.push_back(n);
        std::cout << limits[i] << endl;
    }

    return limits;

}