#include "VecMatMath.hpp"
#include <cmath>
#include <cassert>

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

std::vector<vec3> getDirections(const std::vector<vec3> &spline)
{
    // cannot be 1 point, and if only 2 points, the points cannot be in the same location
    if (spline.size() <= 1
        || (spline.size() == 2 && spline[1] == spline[0])) return std::vector<vec3>();

    std::vector<vec3> directions;

    vec3 firstDirection = unitVec(deduct(spline[1], spline[0]));
    directions.push_back(firstDirection);

    if (spline.size() == 2) {
        directions.push_back(firstDirection);
        return directions;
    }

    for (int i = 1; i < spline.size() - 1; i++) {
        directions.push_back(unitVec(deduct(spline[i + 1],
                                            spline[i - 1])));
    }

    vec3 lastDirection = unitVec(deduct(spline[spline.size() - 1],
                                        spline[spline.size() - 2]));

    directions.push_back(lastDirection);

    assert(spline.size() == directions.size());

    return directions;
}
