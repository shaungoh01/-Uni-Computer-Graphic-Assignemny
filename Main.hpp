
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
    MerryGo maa;
    FerryW ferry;

    void draw(){
        glDisable(GL_CULL_FACE);
         //Quadric Object
    GLUquadricObj *pObj;
    //create and initialize quadric
    pObj = gluNewQuadric();
    gluQuadricDrawStyle(pObj, GLU_FILL);
    gluQuadricNormals(pObj, GLU_FLAT);

    ferry.draw();
    glTranslatef(150.0f, -50.0f, 0.0f);
    maa.draw();
    /*
for(float i= 0; i< 360 ; i+=45.0){
    glPushMatrix();
    glRotatef(i, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 200.0f);
    maa.draw();

    glTranslatef(0.0f, 47.0f, 0.0f);
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glRotatef(-40, 0.0f, 1.0f, 0.0f);
    gluCylinder(pObj, 2.0f, 2.0f, 100.0f, 24, 72);
    glPopMatrix();
}
*/
//free the quadric object
gluDeleteQuadric(pObj);
glEnable(GL_CULL_FACE);
    }
    void tickTime()
    {
        //do nothing, reserved for doing animation
    }
    //for any one-time only initialization of the
    // virtual world before any rendering takes place
    // BUT after OpenGL has been initialized
    void init()
    {
    };
}; //end of namespace CGLab06
};
#endif //YP_CGLAB06_HPP
