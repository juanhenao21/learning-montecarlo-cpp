#ifndef LINKS_H
#define LINKS_H 


struct Link
{
    int source;
    int target;
    double exchange;
};

std::ostream& operator<< (std::ostream& os, Link& l);

#endif