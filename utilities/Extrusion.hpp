#pragma once

#include <vector>
#include "Typedefs.hpp"

class Extrusion
{
public:
    Extrusion(std::vector<vec2> &points, int depth = 1);

    void draw();

    void setDepth(const int d);
    int getDepth() const;

private:
    std::vector<vec2> &points2d;
    int depth;
};
