#ifndef TYPES
#define TYPES

#include <fstream>
#include <random>
#include <string>
#include <vector>

// ******************************************************************************
// ******************************************************************************

// Structures


struct Atom
{
    int id;
    float x, y, z;
    float kx, ky, kz;
    float s;
    float k;
    std::string type;
};


struct Link
{
    int source;
    int target;
    double exchange;
};



struct AtomsLinks
{

    std::vector<Atom> atoms;
    std::vector<Link> links;

    int natoms () const;

    static AtomsLinks read_from_file (std::string filename);
};


// ******************************************************************************
// ******************************************************************************

// Operators

std::ostream& operator<< (std::ostream& os, Atom& a);

std::ostream& operator<< (std::ostream& os, Link& l);

float operator* (const Spin& a, const Spin& b);

std::ostream& operator<< (std::ostream& os, Spin& s);

#endif
