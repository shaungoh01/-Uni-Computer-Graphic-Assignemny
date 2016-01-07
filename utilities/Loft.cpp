//
//  Loft.cpp
//  OpenGL-Utilities-XCODE
//
//  Created by Yong Lian Hii on 30/12/2015.
//  Copyright © 2015 Yong Lian Hii. All rights reserved.
//

#include "Loft.hpp"
#include "VecMatMath.hpp"
#include "Extrusion.hpp"
#include <GLUT/glut.h>
#include <iostream>
Loft::Loft(const std::vector<vec2> &points, const std::vector<vec3> &path): points2d(points),path(path) {
    init();
}
void Loft::init() {
    directions = getDirections(path);
    for(int i = 0; i < points2d.size(); i++)
    {
        std::vector<vec3> row;
        points3d.push_back(row);
    }
    for(auto it = path.begin(); it != path.end(); it++) {
        long i = std::distance( path.begin(), it );
        mat3 rotationMatrix = getRotationMatrix({0,1,0}, directions[i]);
        
        for(auto jt = points2d.begin(); jt != points2d.end(); jt++) {
            vec3 temp = mult(rotationMatrix, {(*jt)[0], 0,(*jt)[1] });
            points3d[i].push_back(add(temp, { (*it)[0], (*it)[1], (*it)[2] }));
        }
    }

    
}
void Loft::draw() {

    glBegin(GL_POLYGON);
    for(auto point : points2d) {
        glVertex3f(point[0], 0, point[1]);
    }
    glEnd();
    
    //Guideline for Loft
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    for (auto it = path.begin(); it != path.end(); it++) {
        if (( it + 1) != path.end()) {
        glVertex3f((*it)[0], (*it)[1], (*it)[2] );
        glVertex3f((*(it+1))[0], (*(it+1))[1], (*(it+1))[2] );
        }
    }
    glEnd();
    glPushMatrix();

    //Draw polygon over loft path
    for(auto it = points3d.begin(); it != points3d.end(); it++) {
//        std::cout << std::distance( temp_points2d.begin(), it ) << std::endl;
        glBegin(GL_POLYGON);
        for(auto jt = (*it).begin(); jt != (*it).end(); jt++) {
            glVertex3f((*jt)[0], (*jt)[1], (*jt)[2]);
        }
        glEnd();
    }

//    for(auto it = path.begin(); it != path.end(); it++) {
//        if (( it + 1) != path.end()) {
//            vec3 difference = { (*(it + 1))[0] - (*it)[0],
//                (*(it + 1))[1] - (*it)[1],
//                (*(it + 1))[2] - (*it)[2]
//            };
//            double distance = sqrt( pow(difference[0],2) + pow(difference[1],2) + pow(difference[2],2));
//
////            Extrusion *extrude = new Extrusion(temp_);
////            extrude->setDepth(distance);
////            extrude->draw();
//
//            
//            
////            glRotatef(45, directions[i][0], directions[i][1], directions[i][2]);
////            glTranslatef(distance,0,0);
//            
////            glTranslatef(difference[0],difference[1],difference[2]);
//        }
//    }
    glPopMatrix();
    
}