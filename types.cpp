#include "types.h"

Spin::Spin(float _x, float _y, float _z) { x = _x; y = _y; z = _z; }
Spin Spin::up () { return Spin(0, 0, 1); }
Spin Spin::down () { return Spin(0, 0, -1); }
