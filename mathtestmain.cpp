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
    int mag = magnitude(found3);

    assert(mag == 1);

    vec3 a = {{ 2, 1, 3 }};
    mat3 m = {{
         {{ 1, 4, 7 }},
         {{ 2, 5, 8 }},
         {{ 3, 6, 9 }}
    }};
    found3 = mult(m, a);
    expected3 = {{ 13, 31, 49 }};

    assert(found3 == expected3);
    return 0;

}
