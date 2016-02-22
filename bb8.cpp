#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include "bb8.hpp"
MyMovingBB8::MyMovingBB8()
{
//Setup Quadric Object
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    posx = 0.0f;
    posy = 0.0f;
    posz = 2.0f;
    roty = 0.0f;

    //initial velocity (in unit per second)
    velx = 40.0f;
    vely = 0.0f;
    velz = 30.0f;
    velroty = 10.0f;
}
MyMovingBB8::~MyMovingBB8()
{
    gluDeleteQuadric(pObj);
}
void MyMovingBB8::draw()
{
    glTranslatef(posx, posy, posz);
    glRotatef(timetick, 0.0f, 1.0f, 0.0f);

    glPushMatrix();

    //glPushMatrix();
//body
    glTranslatef(0.0f, 4.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    gluSphere(pObj,4.0f, 20, 20);
    glTranslatef(0.0f, 4.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    gluSphere(pObj,2.0f, 20, 20);
    glPopMatrix();
//eyes
    glPushMatrix();
    glTranslatef(0.0f, 9.0f, 2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    gluDisk(pObj, 0.0f, 0.4f, 26, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0f, 8.7f, 2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    gluDisk(pObj, 0.0f, 0.2f, 26, 5);
    glPopMatrix();

//antena
    glPushMatrix();
    glTranslatef(0.5f, 9.5f, 0.0f);
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    gluCylinder(pObj, 0.1f, 0.0f, 2, 26, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 9.5f, 0.0f);
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    gluCylinder(pObj, 0.1f, 0.0f, 1, 26, 5);
    glPopMatrix();
}

void MyMovingBB8::drawfence()
{
    srand(time(NULL));
    glDisable(GL_CULL_FACE);
    glPushMatrix();
    glColor3f(rand()%45*0.1, rand()%45*0.1,rand()%45 * 0.001 );
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    gluCylinder(pObj, 25.0f, 25.0f, 5, 26, 5);
    glPopMatrix();
}

void MyMovingBB8::Movebb8()
{
    glPushMatrix();
    //glTranslatef(posx, posy, posz);
    //glRotatef(roty, 0.0f, 1.0f, 0.0f);
    draw();
    glPushMatrix();
}

//elapsetime in milisec
void MyMovingBB8::tickTime(long int elapseTime)
{
    float elapseTimeInSec = elapseTime / 1000.0f;
    posx += elapseTimeInSec * velx;
    posy += elapseTimeInSec * vely;
    posz += elapseTimeInSec * velz;
    roty += elapseTimeInSec * velroty;
    timetick += elapseTime;
    if (posx > 15)
    {
        posx = 30 - posx; //posx = 15 - (posx - 15)
        velx = -velx;
        velroty = -velroty;
        //roty += elapseTimeInSec * velroty;
        //glPushMatrix();
        //glRotatef(elapseTimeInSec *30, 1.0f, 1.0f, 0.0f);

        //glPopMatrix();

    }
    else if (posx < -15)
    {
        posx = -30 - posx; //posx = -15 - (posx -(-15))
        velx = -velx;
        velroty = -velroty;
    }
    if (posz > 15)
    {
        posz = 30 - posz;
        velz = -velz;
        velroty = -velroty;
    }
    else if (posz<-15)
    {
        posz = -30 - posz;
        velz = -velz;
        velroty = -velroty;
    }
}

