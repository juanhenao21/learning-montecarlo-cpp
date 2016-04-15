#ifndef SPIN_H_
#define SPIN_H_

#include <iostream>
#include <random>

struct Spin
{
    public:
        Spin(float _x, float _y, float _z);
        friend std::ostream& operator<< (std::ostream& os, const Spin& s);
        friend float operator* (const Spin& a, const Spin& b);
        static Spin up ();
        static Spin down ();
        static Spin null ();
        static Spin randSpin();

    private:
        double x, y, z;

};

struct SpinGenerator
{
    int generator;
    SpinGenerator (int _case);
    Spin operator() () const;
};

float operator* (const Spin& a, const Spin& b);

std::ostream& operator<< (std::ostream& os, Spin& s);

#endif
