#ifndef ATOM_H_
#define ATOM_H_ 

#include <iostream>

/** 
 * This struct stores the values of different parameters of an atom.
 */
struct Atom
{
    /** Holds the id number of the atom. */
    int id;
    /** Holds the x, y and z coordinates of the atom. */
    float x, y, z;
    /** Holds the anisotropy values in the x, y and z direction. */
    float kx, ky, kz;
    /** Holds the spin of the atom. */
    float s;
    /** Holds the anisotropy of the atom. */
    float k;
    /** Holds the type of the atom */
    std::string type;
};

std::ostream& operator<< (std::ostream& os, Atom& a);

#endif