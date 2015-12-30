#include "VecMatMath.hpp"

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

