#ifndef LINKS_H
#define LINKS_H 

/**
 * This struct stores the interactions of an atom whit its neighbors.
 */
struct Link
{
    /** Holds the source of the interaction. */
    int source;
    /** Holds the target of the interaction. */
    int target;
    /** Holds the exchange interaction between the source and the target. */
    double exchange;
};

std::ostream& operator<< (std::ostream& os, Link& l);

#endif