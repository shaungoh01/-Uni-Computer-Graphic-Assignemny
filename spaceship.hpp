#ifndef YP_SPACESHIP1_HPP
#define YP_SPACESHIP1_HPP
#include "CGLabmain.hpp"
class MySpaceShip
{
public:
    MySpaceShip();
    ~MySpaceShip();
    float ticktick = 0;
    float tickMove = 0;
    int moveUp=0;
    void draw();
    void drawfence();
    void tickTime(long int elapseTime);
    void Movespaceship();
private:
    long int timetick;
    GLUquadricObj *pObj;
    GLfloat posx, posy, posz;
    GLfloat roty;
    GLfloat velx, vely, velz, velroty; //unit per sec
};

#endif
