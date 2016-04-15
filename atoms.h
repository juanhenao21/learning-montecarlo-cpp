#ifndef ATOM_H_
#define ATOM_H_ 

#include <iostream>

struct Atom
{
    int id;
    float x, y, z;
    float kx, ky, kz;
    float s;
    float k;
    std::string type;
};

std::ostream& operator<< (std::ostream& os, Atom& a);

#endif