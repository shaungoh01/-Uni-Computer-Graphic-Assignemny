#include "GL/gl.h"
#include <string>
#include "utilities/VecMatMath.hpp"
#include "MerryGo.hpp"
#include <vector>

MerryGo::MerryGo(){
    tickMove = 0;
    ticktick = 0;
}

void MerryGo::draw(){
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
            glRotatef(i+tickMove, 0.0f, 1.0f, 0.0f);
            glTranslatef(0.0f, 30.0f, 0.0f);
            gluCylinder(pObj, 2.0f, 2.0f, 52.0f, 24, 72);
            glTranslatef(0.0f, 2.0f, 50.0f);
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            gluCylinder(pObj, 2.0f, 2.0f, 32.0f, 24, 72);
        glPopMatrix();

        glPushMatrix();
            glRotatef(i+tickMove, 0.0f, 1.0f, 0.0f);
            glTranslatef(-50.0f, 0.0f, 0.0f);
            jet->draw();
        glPopMatrix();
    }

    //free the quadric object
    gluDeleteQuadric(pObj);
    glEnable(GL_CULL_FACE);
    }

void MerryGo::tickTime(){
    ticktick++;
    if(ticktick == 30){
        ticktick =0;
        tickMove+= 11.25;
    }
}
