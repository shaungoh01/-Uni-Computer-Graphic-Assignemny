#pragma once

#include "VecMatMath.hpp"
#include "Drawable.hpp"
#include <vector>

class Lathe : public Drawable
{
    public:
        Lathe(std::vector<vec2> points);
        virtual ~Lathe();
        void draw() override;

    protected:
    private:
        std::vector< std::vector<vec3> > lathePoints;
};


