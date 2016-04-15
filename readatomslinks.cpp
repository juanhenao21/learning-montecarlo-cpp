#include <algorithm>

#include "readatomslinks.h"
#include "atoms.h"
#include "links.h"
#include "utilities.h"

int ReadAtomsLinks::natoms () const
{
    return atoms.size();
}

ReadAtomsLinks ReadAtomsLinks::read_from_file (std::string filename)
{
    std::vector<Atom> atoms;
    std::vector<Link> links;
    std::ifstream file_(filename.data());

    int natoms, nlinks, ntypes, _;
    char type1;

    if(file_.is_open())
    {

        file_ >> natoms >> nlinks >> ntypes >> _;

        for (int i = 0; i < ntypes; ++i)
        {
            file_ >> type1;
        }

        for (int i=0; i< natoms; i++)
        {
            Atom atom;
            file_ >> atom.id
                >> atom.x >> atom.y >> atom.z
                >> atom.s
                >> atom.kx >> atom.ky >> atom.kz
                >> atom.k
                >> atom.type;
            atoms.push_back(atom);
        }

        for (int i=0; i< nlinks; i++)
        {
            Link link;
            file_ >> link.source >> link.target >> link.exchange;
            links.push_back(link);
        }

        file_.close();
    }

    std::sort(atoms.begin(), atoms.end(), CompAtom());
    std::sort(links.begin(), links.end(), CompLink());

    ReadAtomsLinks al;
    al.atoms = atoms;
    al.links = links;

    return al;
}