
#ifndef REPLICATE_HPP
#define REPLICATE_HPP

#include<vector>
#include "VecMatMath.hpp"
#include "Drawable.hpp"
#include "Mesh.hpp"

class Replicate
{
    public:
        Replicate();
        Replicate(const std::vector<vec3> &points, Drawable *picture);
        void draw();
    private:
        std::vector<vec3> pointsObj;
        std::vector<vec3> plottedPoints;
        Drawable *drawable;
};



#endif // REPLICATE_HPP
