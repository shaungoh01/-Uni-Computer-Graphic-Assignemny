#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <string>
#include <fstream>
#include "utilities/VecMatMath.hpp"
#include "Main.hpp"

using namespace Main;

void MyVirtualWorld::draw(){
    glDisable(GL_CULL_FACE);
         //Quadric Object
    GLUquadricObj *pObj;
    //create and initialize quadric
    pObj = gluNewQuadric();
    gluQuadricDrawStyle(pObj, GLU_FILL);
    gluQuadricNormals(pObj, GLU_FLAT);

        mymovingbb8.drawfence();
        mymovingbb8.draw();

    glPushMatrix();
        glTranslatef(150.0f, 0.0f, 0.0f);
        maa.draw();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-100.0f, 0.0f, 0.0f);
        ferry.draw();
    glPopMatrix();
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
void MyVirtualWorld::tickTime()
    {
        timenew = glutGet(GLUT_ELAPSED_TIME);
        elapseTime = timenew - timeold;
        timeold = timenew;

        mymovingbb8.tickTime(elapseTime);
        ferry.tickTime();
        maa.tickTime();
    }

