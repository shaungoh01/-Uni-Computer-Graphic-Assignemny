#ifndef YP_BB8_HPP
#define YP_BB8_HPP
#include <time.h>
#include "CGLabmain.hpp"

class MyMovingBB8
{
public:
    MyMovingBB8();
    ~MyMovingBB8();
    void draw();
    void drawfence();
    void tickTime(long int elapseTime);
    void Movebb8();
private:
    long int timetick;
    GLUquadricObj *pObj;
    GLfloat posx, posy, posz;
    GLfloat roty;
    GLfloat velx, vely, velz, velroty; //unit per sec
};
#endif
