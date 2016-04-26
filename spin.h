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
        static Spin randSpin(std::mt19937& gen);

    private:
        double x, y, z;

};

struct SpinGenerator
{
    int generator;
    SpinGenerator (int _case);
    Spin operator() () const;
};

inline float operator* (const Spin& a, const Spin& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

std::ostream& operator<< (std::ostream& os, const Spin& s);

#endif
