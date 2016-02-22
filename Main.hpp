
#ifndef MAIN_HPP
#define MAIN_HPP

#include "CGLabmain.hpp"
#include "utilities/Mesh.hpp"
#include "utilities/Extrusion.hpp"
#include "utilities/Loft.hpp"
#include "utilities/Lathe.hpp"
#include "utilities/Replicate.hpp"
#include "MerryGo.hpp"
#include "FerryW.hpp"
#include "spaceship.hpp"
#include "bb8.hpp"
#include "GL/gl.h"
#include <string>
#include <vector>//------------------------------------
    //the main program will call methods from this class
namespace Main {
class Main
{
public:
void draw(){};
};


class MyVirtualWorld
{
    public:
    //create an instance of the MyUmbrella class
    MySpaceShip myspaceship;
    MerryGo maa;
    FerryW ferry;
    MyMovingBB8 mymovingbb8;
    long int timeold, timenew, elapseTime;
    void draw();
    void tickTime();
    void init()
    {
        timeold = glutGet(GLUT_ELAPSED_TIME);
    };
}; //end of namespace CGLab06
};
#endif //YP_CGLAB06_HPP
