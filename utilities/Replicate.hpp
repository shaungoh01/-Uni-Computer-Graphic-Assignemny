
#ifndef REPLICATE_HPP
#define REPLICATE_HPP

#include<vector>
#include "VecMatMath.hpp"
#include "Drawable.hpp"

class Replicate
{
    public:
        Replicate();
        Replicate(const std::vector<vec3> &points);

        void draw();
    private:

};



#endif // REPLICATE_HPP
