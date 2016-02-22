#ifndef FERRYW_HPP
#define FERRYW_HPP

#include "CGLabmain.hpp"
#include "Drawable.hpp"
#include "utilities/Replicate.hpp"
#include "GL/gl.h"
#include <string>
#include <vector>

class FerryW : Drawable
{
public:
    Mesh *deathStar;
    void drawDeath();
    void drawPole(float i);
    void draw();
   // void tickTime(long int elapseTime)

};

#endif
