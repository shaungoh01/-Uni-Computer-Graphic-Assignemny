#include "VecMatMath.hpp"
#include <cmath>

vec3 add(vec3 a, vec3 b)
{
    vec3 c;
    for (int i = 0; i < c.size(); i++) {
        c[i] = a[i] + b[i];
    }

    return c;
}

float dot(vec3 a, vec3 b)
{
    float res = 0;

    for (int i = 0; i < a.size(); i++) {
        res += (a[i] * b[i]);
    }

    return res;
}

float magnitude(vec3 a)
{
    float sumSquare = 0;

    for (auto &b : a) {
        sumSquare += (b*b);
    }

    return std::sqrt(sumSquare);
}

vec3 unitVec(vec3 a)
{
    float mag = magnitude(a);

    return {{ a[0]/mag, a[1]/mag, a[2]/mag }};
}

vec3 cross(vec3 a, vec3 b)
{
    return
    {{
        + (a[1] * b[2] - b[1] * a[2]),
        - (a[0] * b[2] - b[0] * a[2]),
        + (a[0] * b[1] - b[0] * a[1])
    }};
}

vec3 negative(vec3 a)
{
    return {{ -a[0], -a[1], -a[2] }};
}
