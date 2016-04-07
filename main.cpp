#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>

#include "types.h"
#include "utilities.h"
#include "limits.h"

int main(int argc, char* argv[])
{
    // Data reading
    std::vector<Atom> atoms;
    std::vector<Link> links;

    AtomsLinks al = AtomsLinks::read_from_file(argv[1]);
    atoms = al.atoms;
    links = al.links;

    // Link and Atom ordering
    std::sort(links.begin(), links.end(), CompLink());
    std::sort(atoms.begin(), atoms.end(), CompAtom());

    // CSR (Compressed Sparse Row) representation
    // Neighboors, interactions and limits
    Link link;
    std::vector<int> limits;

    CSRMatrix csr = get_limits(links);

    for (int i = 0; i < csr.limits.size(); ++i)
    {
        std::cout << csr.limits[i] << std::endl;
    }

    // Energy calculation
    // Spin sup = Spin::up();
    // Spin sdown = Spin::down();

    // for (int i = 0; i < al.links.size(); ++i)
    // {
    //     Spin Up = Spin::up();
    //     spinUp.push_back(Up);
    // }

}
