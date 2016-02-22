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
    FerryW();
    //~FerryW();
    Mesh *deathStar;
    float ticktick;
    float tickMove;
    void drawDeath();
    void drawPole(float i);
    void drawMoving();
    void draw();
    void tickTime();

};

#endif
