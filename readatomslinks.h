#ifndef READATOMSLINKS_H_
#define READATOMSLINKS_H_

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "atoms.h"
#include "links.h"
#include "utilities.h"

// Structures
struct ReadAtomsLinks
{

    std::vector<Atom> atoms;
    std::vector<Link> links;

    int natoms () const;

    static ReadAtomsLinks read_from_file (std::string filename);
};

#endif