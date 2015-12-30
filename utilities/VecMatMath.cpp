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

