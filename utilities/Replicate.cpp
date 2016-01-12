#include "Replicate.hpp"
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <iostream>

Replicate::Replicate()
{

}

Replicate::Replicate(const std::vector<vec3> &points)
{
    ///Initialized
    pointsObj = getDirections(points);

}

void Replicate::draw()
{
    glBegin(GL_POLYGON);
        for(auto it=pointsObj.begin();it!=pointsObj.end();it++)
        {
            glVertex3f((*it)[0],(*it)[1],(*it)[2]);
            glVertex3f((*it)[2],(*it)[3],(*it)[4]);
        }
    glEnd();

}
