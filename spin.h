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
        friend Spin operator- (const Spin& a, const Spin& b);
        friend Spin operator+ (const Spin& a, const Spin& b);
        static Spin up ();
        static Spin down ();
        static Spin null ();
        static Spin randSpin();
        static Spin randSpin(std::mt19937& gen);
        static float normSpin(const Spin& s);

    //private:
        double x, y, z;

};

struct SpinGenerator
{
    int generator;
    SpinGenerator (int _case);
    Spin operator() () const;
};

struct RandomSpinGenerator
{
    public:
        RandomSpinGenerator(std::mt19937& _gen);
        Spin operator() ();
    private:
        std::mt19937& gen;
};

inline float operator* (const Spin& a, const Spin& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline Spin operator/ (const Spin& a, float b)
{
    return Spin (a.x / b, a.y / b, a.z / b);
}

inline Spin operator- (const Spin& a, const Spin& b)
{
    return Spin (a.x - b.x, a.y - b.y, a.z - b.z);
}

inline Spin operator+ (const Spin& a, const Spin& b)
{
    return Spin (a.x + b.x, a.y + b.y, a.z + b.z);
}

std::ostream& operator<< (std::ostream& os, const Spin& s);

#endif
