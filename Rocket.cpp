#include "GL/gl.h"
#include <string>
#include "utilities/VecMatMath.hpp"
#include "Rocket.hpp"
#include <vector>
//class definition / implementation

Rocket::Rocket(){
    init();
}
void Rocket::init(){
     std::vector<vec2> lpoints1 = {
                {{ 0, 68 }},
                {{ 5, 63 }},
                {{ 6, 39 }},
                {{ 6, 36 }},
                {{ 6, 34 }},
                {{ 6, 32 }},
                {{ 6, 30 }},
                {{ 6, 22 }},
                {{ 7, 17 }},
            };
        lathe = new Lathe(lpoints1, 22);
        std::vector<vec2> lpoints = {
                {{ 7, 17 }},
                {{ 10, 13 }},
                {{ 11, 9 }},
                {{ 12, 4 }},
                {{ 12, 1 }},
                {{ 12, 0 }},
            };
        base = new Lathe(lpoints, 22);
}
void Rocket::drawWing()
{
glColor3f(1.0f, 1.0f, 1.0f );
 glDisable(GL_CULL_FACE);
 glBegin(GL_QUADS);
 glVertex3f(0.0f , 0.0f , 0.0f );
 glVertex3f(0.0f , 17.0f , 0.0f );
 glVertex3f(13.0f , 17.0f , 0.0f );
 glVertex3f(20.0f , 0.0f , 0.0f );
 glEnd();
 glEnable(GL_CULL_FACE);

}
void Rocket::draw(){

glColor3f(1.0f, 1.0f, 1.0f );
 lathe->draw();
 glColor3f(1.0f, 0.0f, 0.0f );
 base->draw();
drawWing();
glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
drawWing();
glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
drawWing();
glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
drawWing();
}

