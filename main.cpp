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

    get_limits(links);

    // for (int i = 0; i < limits.size(); ++i)
    // {
    //     cout << limits[i] << endl;
    // }

    // Energy calculation
    // Spin sup = Spin::up();
    // Spin sdown = Spin::down();

    // for (int i = 0; i < al.links.size(); ++i)
    // {
    //     Spin Up = Spin::up();
    //     spinUp.push_back(Up);
    // }

}
