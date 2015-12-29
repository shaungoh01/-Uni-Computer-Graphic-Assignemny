#pragma once

#include <array>

typedef std::array<float, 3> vec3;
typedef std::array<float, 2> vec2;

float dot(vec3 a, vec3 b);
float magnitude(vec3 a);

vec3 add(vec3 a, vec3 b);
vec3 unitVec(vec3 a);
vec3 cross(vec3 a, vec3 b);
vec3 negative(vec3 a);
