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
    Rocket rocket;
    Mesh *jet;

    void draw(){
    glDisable(GL_CULL_FACE);
         //Quadric Object
    GLUquadricObj *pObj;
    //create and initialize quadric
    pObj = gluNewQuadric();
    gluQuadricDrawStyle(pObj, GLU_FILL);
    gluQuadricNormals(pObj, GLU_FLAT);
    jet = new Mesh("data/space-ship.obj");
    jet->setFlatColor({{ .3, .1, 1. }});
    jet->setTranslateX(-10.5f);
    jet->setRotateY(-45.0f);
    rocket.draw();

    glTranslatef(0.0f, 20.0f, 0.0f);


for(float i= 0; i<360 ; i+=45.0){


    glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f );
        glRotatef(i, 0.0f, 1.0f, 0.0f);
        glTranslatef(0.0f, 30.0f, 0.0f);
        gluCylinder(pObj, 2.0f, 2.0f, 52.0f, 24, 72);
        glTranslatef(0.0f, 2.0f, 50.0f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(pObj, 2.0f, 2.0f, 32.0f, 24, 72);
    glPopMatrix();

    glPushMatrix();
        glRotatef(i, 0.0f, 1.0f, 0.0f);
        glTranslatef(-50.0f, 0.0f, 0.0f);
        jet->draw();
    glPopMatrix();
}

//free the quadric object
gluDeleteQuadric(pObj);
glEnable(GL_CULL_FACE);
    };
};

#endif
