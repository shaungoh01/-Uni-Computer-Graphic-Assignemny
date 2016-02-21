#ifndef ROCKET_HPP
#define ROCKET_HPP

#include "utilities/Lathe.hpp"
#include "Drawable.hpp"
#include <string>
#include <vector>
    class Rocket : public Drawable
    {
        public:
        Rocket();
        void init();
        void draw();
        void drawWing();
        Lathe *lathe;
        Lathe *base;
    };

#endif //YP_CGLAB06_HPP

