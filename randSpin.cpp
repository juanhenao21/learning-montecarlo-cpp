#include <iostream>
#include <random>
#include <math.h>

#include "types.h"

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