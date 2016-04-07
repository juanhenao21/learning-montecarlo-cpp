#include "types.h"

Spin::Spin(float _x, float _y, float _z) { x = _x; y = _y; z = _z; }
Spin Spin::up () { return Spin(0, 0, 1); }
Spin Spin::down () { return Spin(0, 0, -1); }


AtomsLinks AtomsLinks::read_from_file (std::string filename)
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

    AtomsLinks al;
    al.atoms = atoms;
    al.links = links;

    return al;
}


std::ostream& operator<< (std::ostream& os, Atom& a)
{
    os << "Atom: " << a.id << " of type: " << a.type;
    return os;
}


std::ostream& operator<< (std::ostream& os, Link& l)
{
    os << "Atom: " << l.source << " with atom: " << l.target << " with exchange " << l.exchange;
    return os;
}


float operator* (const Spin& a, const Spin& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}


std::ostream& operator<< (std::ostream& os, Spin& s)
{
    os << "(" << s.x << ", " << s.y << ", " << s.z << ")";
    return os;
}
