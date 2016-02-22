#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include "spaceship.hpp"
MySpaceShip::MySpaceShip()
{
//Setup Quadric Object
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    posx = 0.0f;
    posy = 10.0f;
    posz = 2.0f;
    roty = 0.0f;

    //initial velocity (in unit per second)
    velx = 0.0f;
    vely = 3.0f;
    velz = 0.0f;
    //velroty = 10.0f;
}
MySpaceShip::~MySpaceShip()
{
    gluDeleteQuadric(pObj);
}

void MySpaceShip::draw()
{
    glTranslatef(posx, posy, posz);
    glRotatef(timetick, 0.0f, 1.0f, 0.0f);
    srand(time(NULL));

    glDisable(GL_CULL_FACE);

    //front
    glPushMatrix();
    glTranslatef(0.0f, 10.0f, 0.0f);
    glColor3f(0.1f, 0.1f, 0.1f);
    gluCylinder(pObj, 5.0f, 0.0f, 10, 26, 5);
    glPopMatrix();

    //body
    glPushMatrix();
    glTranslatef(0.0f, 10.0f, -15.0f);
    glColor3f(rand()%45*0.1, rand()%45*0.1,rand()%45 * 0.01 );
    gluCylinder(pObj, 5.0f, 5.0f, 15, 26, 5);
    glPopMatrix();

    //back
    glPushMatrix();
    glTranslatef(0.0f, 10.0f, -15.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    gluDisk(pObj, 0.0f, 5.0f, 26, 5);
    glPopMatrix();

    //top mirror
    glPushMatrix();
    glTranslatef(0.0f, 14.0f, -8.0f);
    glColor3f(0.0f, 1.0f, 1.0f);
    gluSphere(pObj,4.0f, 20, 20);
    glPopMatrix();

    //left wing alpha
    glPushMatrix();
    glTranslatef(10.0f, 10.0f, -2.0f);
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glColor3f(0.1f, 0.1f, 0.1f);
    gluCylinder(pObj, 3.0f, 3.0f, 3, 26, 5);
    //fan1
    glTranslatef(0.0f, -3.0f, 2.0f);
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    gluCylinder(pObj, 0.5f, 0.5f, 6, 26, 5);
    //fan2
    glTranslatef(3.0f, 1.0f, 3.0f);
    glRotatef(-90, 0.0f, 1.0f, 0.0f);
   glColor3f(0.5f, 0.5f, 0.5f);
    gluCylinder(pObj, 0.5f, 0.5f, 6, 26, 5);
    glPopMatrix();

    //left wing beta
    glPushMatrix();
    glTranslatef(10.0f, 10.0f, -12.0f);
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glColor3f(0.1f, 0.1f, 0.1f);
    gluCylinder(pObj, 3.0f, 3.0f, 3, 26, 5);
    //fan1
    glTranslatef(0.0f, -3.0f, 2.0f);
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    gluCylinder(pObj, 0.5f, 0.5f, 6, 26, 5);
    //fan2
    glTranslatef(3.0f, 1.0f, 3.0f);
    glRotatef(-90, 0.0f, 1.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    gluCylinder(pObj, 0.5f, 0.5f, 6, 26, 5);
    glPopMatrix();

    //right wing alpha
    glPushMatrix();
    glTranslatef(-10.0f, 10.0f, -2.0f);
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glColor3f(0.1f, 0.1f, 0.1f);
    gluCylinder(pObj, 3.0f, 3.0f, 3, 26, 5);
    //fan1
    glTranslatef(0.0f, -3.0f, 2.0f);
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    gluCylinder(pObj, 0.5f, 0.5f, 6, 26, 5);
    //fan2
    glTranslatef(3.0f, 1.0f, 3.0f);
    glRotatef(-90, 0.0f, 1.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    gluCylinder(pObj, 0.5f, 0.5f, 6, 26, 5);
    glPopMatrix();

    //right wing beta
    glPushMatrix();
    glTranslatef(-10.0f, 10.0f, -12.0f);
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glColor3f(0.1f, 0.1f, 0.1f);
    gluCylinder(pObj, 3.0f, 3.0f, 3, 26, 5);
    //fan1
    glTranslatef(0.0f, -3.0f, 2.0f);
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    gluCylinder(pObj, 0.5f, 0.5f, 6, 26, 5);
    //fan2
    glTranslatef(3.0f, 1.0f, 3.0f);
    glRotatef(-90, 0.0f, 1.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    gluCylinder(pObj, 0.5f, 0.5f, 6, 26, 5);
    glPopMatrix();

    //exhaust pipe
    glPushMatrix();
    glTranslatef(0.0f, 10.0f, -20.0f);
    glColor3f(0.1f, 0.1f, 0.1f);
    gluCylinder(pObj, 4.0f, 2.0f, 6, 26, 5);
    glPopMatrix();

    //EP back
    glPushMatrix();
    glTranslatef(0.0f, 10.0f, -20.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    gluDisk(pObj, 0.0f, 4.0f, 26, 5);
    glPopMatrix();

    glEnable(GL_CULL_FACE);
}

void MySpaceShip::Movespaceship()
{
    glPushMatrix();
    glTranslatef(0.0f , tickMove , 0.0f );
    //glRotatef(roty, 0.0f, 1.0f, 0.0f);
    draw();
    glPopMatrix();
}

void MySpaceShip::drawfence()
{
    glDisable(GL_CULL_FACE);

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    gluCylinder(pObj, 25.0f, 25.0f, 7, 26, 5);
    glPopMatrix();
}

//elapsetime in milisec
void MySpaceShip::tickTime(long int elapseTime)
{
    ticktick++;
    if(ticktick == 30){
        if(tickMove < 51.0 && moveUp == 1){
            ticktick =0;
            tickMove+= 5.0;
            if(tickMove >= 51.0)
                moveUp = 0;
        }else if(moveUp == 0){
            ticktick=0;
            tickMove-= 5.0;
            if(tickMove < 0.0){
                moveUp = 1;
            }
        }
    }
}

