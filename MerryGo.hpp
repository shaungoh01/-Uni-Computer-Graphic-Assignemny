#ifndef MERRYGO_HPP
#define MERRYGO_HPP

#include "CGLabmain.hpp"
#include "Drawable.hpp"
#include "utilities/Replicate.hpp"
#include "Rocket.hpp"
#include "GL/gl.h"
#include <string>
#include <vector>

class MerryGo : Drawable
{
    public:
    //create an instance of the MyUmbrella class
    MerryGo();
    Rocket rocket;
    float ticktick;
    float tickMove;
    Mesh *jet;
    void draw();
    void tickTime();
};

#endif
