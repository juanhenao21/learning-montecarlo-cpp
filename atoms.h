#ifndef ATOM_H_
#define ATOM_H_ 

#include <iostream>

/** 
 * This struct stores the values of different parameters of an atom.
 */
class Atom
{
public:

friend std::ostream& operator<< (std::ostream& os, Atom& a);
friend std::istream& operator>> (std::istream& is, Atom& atom);

    int id;
    float x, y, z;
    float kx, ky, kz;
    float s;
    float k;
    std::string type;
};


#endif