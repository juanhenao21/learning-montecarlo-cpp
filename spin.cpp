#include "spin.h"

Spin::Spin(float _x, float _y, float _z) { x = _x; y = _y; z = _z; }
Spin Spin::up () { return Spin(0, 0, 1); }
Spin Spin::down () { return Spin(0, 0, -1); }
Spin Spin::null () { return Spin(0, 0, 0); }
Spin Spin::randSpin ()
{
    std::random_device rd;
    std::mt19937 a(rd());
    std::mt19937 b(rd());
    std::uniform_real_distribution<> dis(-1, 1);

    double x1, x2;
    double x, y, z;

    do
    {
        x1 = dis(a);
        x2 = dis(b);
        x = 2 * x1 * sqrt(1 - x1 * x1 - x2 * x2);
        y = 2 * x2 * sqrt(1 - x1 * x1 - x2 * x2);
        z = 1 - 2 * (x1 * x1 + x2 * x2);
    } while (x1 * x1 + x2 * x2 >= 1);

    return Spin(x, y, z);
}
Spin Spin::randSpin (std::mt19937& gen)
{
    std::uniform_real_distribution<> dis(-1, 1);

    double x1, x2;
    double x, y, z;

    do
    {
        x1 = dis(gen);
        x2 = dis(gen);
        x = 2 * x1 * sqrt(1 - x1 * x1 - x2 * x2);
        y = 2 * x2 * sqrt(1 - x1 * x1 - x2 * x2);
        z = 1 - 2 * (x1 * x1 + x2 * x2);
    } while (x1 * x1 + x2 * x2 >= 1);

    return Spin(x, y, z);
}


SpinGenerator::SpinGenerator (int _case) : generator(_case) {}

Spin SpinGenerator::operator() () const {
        switch (generator) {
            case 0:
                return Spin::up();
            case 1:
                return Spin::down();
            case 2:
                return Spin::randSpin();
            default:
                return Spin::null();
    }
}

float operator* (const Spin& a, const Spin& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}


std::ostream& operator<< (std::ostream& os, const Spin& s)
{
    os << "(" << s.x << ", " << s.y << ", " << s.z << ")";
    return os;
}