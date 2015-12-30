#include <iostream>
#include <cassert>
#include "utilities/VecMatMath.hpp"


int main()
{
    vec2 found2, expected2;
    std::vector<vec2> points = { {{ 0, 2 }}, {{ 2, 0 }} };
    found2 = findCenter(points);
    expected2 = {{ 1, 1 }};

    assert(found2 == expected2);

    vec3 found3, expected3;
    found3 = cross({{ 1, 2, -5 }}, {{ 9, -3, 1 }});
    expected3 = {{ -13, -46, -21 }};

    assert(found3 == expected3);

    found3 = unitVec(expected3);
    int m = magnitude(found3);

    assert(m == 1);
    return 0;

}
