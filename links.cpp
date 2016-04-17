#include <iostream>
#include "links.h"

/*
 * Operator definition.
 * <p> 
 * << operator Link structure.
 * This define the operation of Link structure with <<
 * operator. The operator prints the following representation
 * of the Link struct
 *
 * os << "Atom: " << l.source << " with atom: " << l.target << " with exchange " << l.exchange;
 * @return the os content
 */
std::ostream& operator<< (std::ostream& os, Link& l)
{
    os << "Atom: " << l.source << " with atom: " << l.target << " with exchange " << l.exchange;
    return os;
}
