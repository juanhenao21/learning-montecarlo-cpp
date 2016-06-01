#ifndef UTILITIES_H_
#define UTILITIES_H_

/**
 * Operator definition.
 * << operator std::vector of structures.
 * This define the operation of a std::vector of structures with <<
 * operator. The operator prints the following representation
 * of the vector
 *
 * os << v[i] << std::endl;
 * @return the os content
 */
    template<typename T>
std::ostream& operator<< (std::ostream& os, std::vector<T>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i] << std::endl;
    }
    return os;
}

/**
 * <h1> Compare Link source </h>
 * The CompLink struct compares two sources from two Link structures
 *
 */
struct CompLink
{
    /**
     * This method is used to compare the value between two struct members
     * of the tipe Link.
     *
     * @param a  this is the first parameter to operator method
     * @param b  this is the second parameter to operator method
     * @return  bool this returns True if a < b, and False if b > a
     */
    bool operator() (const Link &a, const Link &b)
    {
        return a.source < b.source;
    }
};

/**
 * <h1> Compare Atom id </h>
 * The CompAtom struct compares two ids from two Atom structures
 *
 */
struct CompAtom
{
    /**
     * This method is used to compare the value between two struct members
     * of the tipe Atom.
     *
     * @param a  this is the first parameter to operator method
     * @param b  this is the second parameter to operator method
     * @return  bool this returns True if a < b, and False if b > a
     */
    bool operator() (const Atom &a, const Atom &b)
    {
        return a.id < b.id;
    }
};

#endif
