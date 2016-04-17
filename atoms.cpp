#include <iostream>

#include "atoms.h"

/*
 * Operator definition.
 * <p> 
 * << operator Atom structure.
 * This define the operation of Atom structure with <<
 * operator. The operator prints the following representation
 * of the Atom struct
 *
 * os << "Atom: " << a.id << " of type: " << a.type;
 * @return the os content
 */
std::ostream& operator<< (std::ostream& os, Atom& a)
{
    os << "Atom: " << a.id << " of type: " << a.type;
    return os;
}
