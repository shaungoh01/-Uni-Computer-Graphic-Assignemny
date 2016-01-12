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

Replicate::Replicate(const std::vector<vec3> &points,Drawable *picture)
{
    ///Initialized
    pointsObj = getDirections(points);
    plottedPoints = points;
    drawable =  picture;
}

void Replicate::draw()
{
    glBegin(GL_LINES);
        glColor3f(0.0f,1.0f,0.0f);
        for(auto it=plottedPoints.begin();it!=plottedPoints.end();it++)
        {
            glVertex3f((*it)[0],(*it)[1],(*it)[2]);
            glVertex3f((*(it+1))[0],(*(it+1))[1],(*(it+1))[2]);
        }
    glEnd();


        for(auto it=plottedPoints.begin();it!=plottedPoints.end();it++)
        {
            glPushMatrix();
                glTranslatef((*it)[0], (*it)[1],(*it)[2]);
                drawable->draw();
            glPopMatrix();
        }




}
