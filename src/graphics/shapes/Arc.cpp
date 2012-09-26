#include "Arc.h"
#define STEPSIZE M_PI/180

namespace phantom{
    Arc::Arc(float x, float y, float radius, float start, float end) : Line(0.0f, 0.0f, 0.0f, 0.0f) {
        this->x = x;
        this->y = y;
        this->radius = radius;
        this->start = start;
        this->end = end;
        drawArc();
    }

    void Arc::drawArc(){
        double vx, vy, vx1,vy1;
        double angle, ang0, ang1;

        ang0 = start;
        ang1 = end;

        for(angle = ang0; angle <= ang1; angle+= STEPSIZE){
            vx = radius*cos(angle);
            vy = radius*sin(angle);
            vx1 = radius*cos(angle + STEPSIZE);
            vy1 = radius*sin(angle + STEPSIZE);

			Line::drawLine(vx1, vy1, vx, vy, vx1, vy1);
        }
    }
} /* namespace Phantom */ 