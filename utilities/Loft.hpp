//
//  Loft.hpp
//  OpenGL-Utilities-XCODE
//
//  Created by Yong Lian Hii on 30/12/2015.
//  Copyright © 2015 Yong Lian Hii. All rights reserved.
//

#ifndef Loft_hpp
#define Loft_hpp

#include "VecMatMath.hpp"
#include <vector>

class Loft {
public:
    Loft(const std::vector<vec2> &points, const std::vector<vec3> &path);
    void draw();
    
private:
    const std::vector<vec2> &points2d;
    const std::vector<vec3> &path;
};


#endif /* Loft_hpp */
