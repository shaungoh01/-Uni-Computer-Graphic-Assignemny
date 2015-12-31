#include "VecMatMath.hpp"
#include <cmath>

#define PI 3.14159265

using namespace std;

vec3 cross(const vec3 &a, const vec3 &b)
{
    return
    {{
        + (a[1] * b[2] - b[1] * a[2]),
        - (a[0] * b[2] - b[0] * a[2]),
        + (a[0] * b[1] - b[0] * a[1])
    }};
}

vec3 mult(const mat3& m, const vec3& a)
{
    return {{
        a[0] * m[0][0] + a[1] * m[1][0] + a[2] * m[2][0],
        a[0] * m[0][1] + a[1] * m[1][1] + a[2] * m[2][1],
        a[0] * m[0][2] + a[1] * m[1][2] + a[2] * m[2][2]
    }};
}

mat3 getRotationMatrix(vec3 axis, float rads)
{
    axis = unitVec(axis);

    return {{
        {{
            cos(rads) + (axis[0] * axis[0]) * (1 - cos(rads)),
            (axis[1] * axis[0]) * (1 - cos(rads)) + axis[2] * sin(rads),
            (axis[2] * axis[0]) * (1 - cos(rads)) - axis[1] * sin(rads)
        }},
        {{
            (axis[0] * axis[1]) * (1 - cos(rads)) - axis[2] * sin(rads),
            cos(rads) + (axis[1] * axis[1]) * (1 - cos(rads)),
            (axis[2] * axis[1]) * (1 - cos(rads)) + axis[0] * sin(rads)
        }},
        {{
            (axis[0] * axis[2]) * (1 - cos(rads)) + axis[1] * sin(rads),
            (axis[1] * axis[2]) * (1 - cos(rads)) - axis[0] * sin(rads),
            cos(rads) + (axis[2] * axis[2]) * (1 - cos(rads))
        }}
    }};
}


