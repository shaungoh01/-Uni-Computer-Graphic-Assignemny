#include "GL/gl.h"
#include <string>
#include "utilities/VecMatMath.hpp"
#include "FerryW.hpp"
#include <vector>

void FerryW::drawDeath(){
        glDisable(GL_CULL_FACE);
                 //Quadric Object
        GLUquadricObj *pObj;
            //create and initialize quadric
        pObj = gluNewQuadric();
        gluQuadricDrawStyle(pObj, GLU_FILL);
        gluQuadricNormals(pObj, GLU_FLAT);



        glColor3f(0.7f, 0.7f, 0.7f);

        gluSphere(pObj, 8.0f, 24, 12);

        glPushMatrix();
            glColor3f(0.0f, 0.0f, 0.0f);
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.0f, 0.0f, -1.0f);
            gluCylinder(pObj, 8.0f, 8.0f, 2.0f, 72, 4);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.3f, 0.3f, 0.3f);
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.0f, 0.0f, -5.5f);
            gluCylinder(pObj, 6.0f, 6.0f, 0.5f, 72, 4);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.3f, 0.3f, 0.3f);
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.0f, 0.0f, -4.5f);
            gluCylinder(pObj, 6.6f, 6.6f, 0.5f, 72, 4);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.3f, 0.3f, 0.3f);
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.0f, 0.0f, 2.5f);
            gluCylinder(pObj, 7.6f, 7.6f, 0.5f, 72, 4);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.3f, 0.3f, 0.3f);
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glTranslatef(0.0f, 0.0f, 5.5f);
            gluCylinder(pObj, 6.0f, 6.0f, 0.5f, 72, 4);
        glPopMatrix();

        glColor3f(0.6f, 0.6f, 0.6f);
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, 8.0f);
            gluDisk(pObj, 1.0f, 4.0f, 26, 13);
        glPopMatrix();

        gluDeleteQuadric(pObj);
        glEnable(GL_CULL_FACE);
}

void FerryW::drawPole(float i){
            glDisable(GL_CULL_FACE);
                 //Quadric Object
            GLUquadricObj *pObj;
            //create and initialize quadric
            pObj = gluNewQuadric();
            gluQuadricDrawStyle(pObj, GLU_FILL);
            gluQuadricNormals(pObj, GLU_FLAT);
        glPushMatrix();
            glColor3f(1.0f, 1.0f, 1.0f);
            glRotatef(90, 1.0f, 0.0f, 0.0f);
            gluCylinder(pObj, 0.5f, 0.5f, i, 24, 72);
        glPopMatrix();
            gluDeleteQuadric(pObj);
            glEnable(GL_CULL_FACE);
}

void FerryW::draw(){
        glTranslatef(0.0f, 50.0f, 0.0f);
        drawDeath();
        for(float i= 0; i<360 ; i+=45.0){
                glPushMatrix();
                    glRotatef(i, 0.0f, 0.0f, 1.0f);
                    drawPole(40.0f);
                    glTranslatef(0.0f, 40.0f, 0.0f);
                    glRotatef(-i, 0.0f, 0.0f, 1.0f);
                    drawDeath();
                glPopMatrix();
                glPushMatrix();
                    glRotatef(i, 0.0f, 0.0f, 1.0f);
                    glTranslatef(0.0f, 40.0f, 0.0f);
                    glRotatef(-i, 0.0f, 0.0f, 1.0f);
                    drawDeath();
                glPopMatrix();
        }

                glPushMatrix();
                    glRotatef(25, 0.0f, 0.0f, 1.0f);
                    glRotatef(20, 1.0f, 0.0f, 0.0f);
                    drawPole(60.0f);
                glPopMatrix();


                glPushMatrix();
                    glRotatef(25, 0.0f, 0.0f, 1.0f);
                    glRotatef(-20, 1.0f, 0.0f, 0.0f);
                    drawPole(60.0f);
                glPopMatrix();


                glPushMatrix();
                    glRotatef(-25, 0.0f, 0.0f, 1.0f);
                    glRotatef(20, 1.0f, 0.0f, 0.0f);
                    drawPole(60.0f);
                glPopMatrix();


                glPushMatrix();
                    glRotatef(-25, 0.0f, 0.0f, 1.0f);
                    glRotatef(-20, 1.0f, 0.0f, 0.0f);
                    drawPole(60.0f);
                glPopMatrix();

                 glBegin(GL_QUADS);
                    glDisable(GL_CULL_FACE);
                    glColor3f(0.4f, 0.4f, 0.4f);
                    glVertex3f(50.0f , -50.0f , -30.0f);
                    glVertex3f(-50.0f , -50.0f , -30.0f);
                    glVertex3f(-50.0f , -50.0f , 30.0f);
                    glVertex3f(50.0f , -50.0f , 30.0f);
                    glEnable(GL_CULL_FACE);
                 glEnd();
    }
