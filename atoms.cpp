#include <iostream>

#include "atoms.h"

std::ostream& operator<< (std::ostream& os, Atom& a)
{
    os << "Atom: " << a.id << " of type: " << a.type;
    return os;
}