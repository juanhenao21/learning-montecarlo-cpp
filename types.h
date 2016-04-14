#ifndef TYPES
#define TYPES

#include <string>
#include <fstream>
#include <vector>

// ******************************************************************************
// ******************************************************************************

// Structures


struct Atom
{
    int id;
    float x, y, z;
    float kx, ky, kz;
    float s;
    float k;
    std::string type;
};


struct Link
{
    int source;
    int target;
    double exchange;
};


struct Spin
{
    public:

        Spin(float _x, float _y, float _z);

        friend std::ostream& operator<< (std::ostream& os, Spin& s);
        friend float operator* (const Spin& a, const Spin& b);

        static Spin up ();
        static Spin down ();
        static Spin null ();
        static Spin randSpin();

    private:

        double x, y, z;

};

struct AtomsLinks
{

    std::vector<Atom> atoms;
    std::vector<Link> links;

    int natoms () const;

    static AtomsLinks read_from_file (std::string filename);
};

struct SpinGenerator
{
    int generator;

    SpinGenerator (int _case) : generator(_case) {}

    Spin operator() ();
};

// ******************************************************************************
// ******************************************************************************

// Operators

std::ostream& operator<< (std::ostream& os, Atom& a);

std::ostream& operator<< (std::ostream& os, Link& l);

float operator* (const Spin& a, const Spin& b);

std::ostream& operator<< (std::ostream& os, Spin& s);

#endif
