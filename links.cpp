#include <iostream>
#include "links.h"

std::ostream& operator<< (std::ostream& os, Link& l)
{
    os << "Atom: " << l.source << " with atom: " << l.target << " with exchange " << l.exchange;
    return os;
}